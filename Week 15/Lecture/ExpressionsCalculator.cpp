#include <iostream>
#include <assert.h>
#include "String and StringView/MyString.h"
#include "String and StringView/StringView.h"

class BooleanInterpretation
{
public:
	void set(char ch, bool value)
	{
		assert(ch >= 'a' && ch <= 'z');
		values[ch - 'a'] = value;
	}

	bool operator()(char ch) const
	{
		assert(ch >= 'a' && ch <= 'z');
		return values[ch - 'a'];
	}

	size_t getTrueCount() const
	{
		size_t count = 0;
		for (int i = 0; i < 26; i++)
		{
			if (values[i])
			{
				count++;
			}
		}

		return count;
	}

	void excludeValuesByMask(unsigned mask)
	{
		for (int i = 25; i >= 0; i--)
		{
			if (values[i])
			{
				if (mask % 2 == 0)
				{
					values[i] = false;
				}

				mask /= 2;
			}
		}
	}


private:
	bool values[26] = { false };
};

struct BooleanExpression
{
	BooleanExpression() = default;
	BooleanExpression(const BooleanExpression& other) = delete;
	BooleanExpression& operator=(const BooleanExpression& other) = delete;
	virtual ~BooleanExpression() = default;

	virtual bool eval(const BooleanInterpretation& interpret) const = 0;
	virtual void populateVariables(BooleanInterpretation& interpret) const = 0;
	virtual BooleanExpression* clone() const = 0;
};

struct Var : BooleanExpression
{
	Var(char ch): ch(ch){}
	bool eval(const BooleanInterpretation& interpret) const override
	{
		return interpret(ch);
	}

	BooleanExpression* clone() const override
	{
		return new Var(ch);
	}

	void populateVariables(BooleanInterpretation& interpret) const override
	{
		interpret.set(ch, true);
	}

private:
	char ch;
};


struct UnaryOperation : BooleanExpression
{
	UnaryOperation(BooleanExpression* expr): expr(expr){}

	void populateVariables(BooleanInterpretation& interpret) const override
	{
		expr->populateVariables(interpret);
	}

	~UnaryOperation()
	{
		delete expr;
	}

protected:
	BooleanExpression* expr;
};


struct Negation : UnaryOperation
{
	Negation(BooleanExpression* expr): UnaryOperation(expr){}

	BooleanExpression* clone() const override
	{
		return new Negation(expr->clone());
	}

	bool eval(const BooleanInterpretation& interpret) const override
	{
		return !expr->eval(interpret);
	}

};

struct BinaryOperation : BooleanExpression
{
	BinaryOperation(BooleanExpression* left, BooleanExpression* right): left(left), right(right){}

	void populateVariables(BooleanInterpretation& interpret) const override
	{
		left->populateVariables(interpret);
		right->populateVariables(interpret);
	}

	~BinaryOperation()
	{
		delete left;
		delete right;
	}

protected:
	BooleanExpression* left;
	BooleanExpression* right;
};


struct Conjunction : BinaryOperation
{
	Conjunction(BooleanExpression* left, BooleanExpression* right) : BinaryOperation(left, right){}

	BooleanExpression* clone() const override
	{
		return new Conjunction(left->clone(), right->clone());
	}

	bool eval(const BooleanInterpretation& interpret) const override
	{
		return left->eval(interpret) && right->eval(interpret);
	}
};

struct Disjunction : BinaryOperation
{
	Disjunction(BooleanExpression* left, BooleanExpression* right):BinaryOperation(left, right){}

	BooleanExpression* clone() const override
	{
		return new Disjunction(left->clone(), right->clone());
	}

	bool eval(const BooleanInterpretation& interpret) const override
	{
		return left->eval(interpret) || right->eval(interpret);
	}
};

struct Implies : BinaryOperation
{
	Implies(BooleanExpression* left, BooleanExpression* right): BinaryOperation(left ,right){}

	BooleanExpression* clone() const override
	{
		return new Implies(left->clone(), right->clone());
	}

	bool eval(const BooleanInterpretation& interpret) const override
	{
		return !left->eval(interpret) || right->eval(interpret);
	}

};

BooleanExpression* expressionFactory(StringView str)
{
	str = str.substr(1, str.length() - 2); //remove brackets

	if (str.length() == 1)
	{
		return new Var(str[0]);
	}

	unsigned count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			count++;
		}

		else if (str[i] == ')')
		{
			count--;
		}

		else if (count == 0)
		{
			switch (str[i])
			{
				case '!': return new Negation(expressionFactory(str.substr(i + 1, str.length() - i - 1)));
				case '&': return new Conjunction(expressionFactory(str.substr(0, i)), expressionFactory(str.substr(i + 1, str.length() - i - 1)));
				case '|': return new Disjunction(expressionFactory(str.substr(0, i)), expressionFactory(str.substr(i + 1, str.length() - i - 1)));
				case '>': return new Implies(expressionFactory(str.substr(0, i)), expressionFactory(str.substr(i + 1, str.length() - i - 1)));
			}
		}
	}

	throw std::invalid_argument("Invalid expression!");
}

class BooleanExpressionHandler
{
private:
	BooleanInterpretation myVariables;
	BooleanExpression* expr = nullptr;

	void copyFrom(const BooleanExpressionHandler& other)
	{
		expr = other.expr->clone();
		myVariables = other.myVariables;
	}

	void moveFrom(BooleanExpressionHandler&& other)
	{
		expr = other.expr;
		myVariables = std::move(other.myVariables);
		other.expr = nullptr;
	}

	void free()
	{
		delete expr;
	}

	bool checkAllTruthAssignments(bool value) const
	{
		size_t varsCount = myVariables.getTrueCount();
		std::cout << varsCount << std::endl;
		size_t powerOfTwo = 1 << varsCount;
		for (int i = 0; i < powerOfTwo; i++)
		{
			BooleanInterpretation current = myVariables;
			current.excludeValuesByMask(i);
			if (expr->eval(current) != value)
			{
				return false;
			}
		}

		return true;
	}

public:

	BooleanExpressionHandler(const MyString& str)
	{
		expr = expressionFactory(str);
		expr->populateVariables(myVariables);
	}

	BooleanExpressionHandler(const BooleanExpressionHandler& other)
	{
		copyFrom(other);
	}

	BooleanExpressionHandler& operator=(const BooleanExpressionHandler& other)
	{
		if (this != &other)
		{
			free();
			copyFrom(other);
		}

		return *this;
	}

	BooleanExpressionHandler(BooleanExpressionHandler&& other) noexcept
	{
		moveFrom(std::move(other));
	}

	BooleanExpressionHandler& operator=(BooleanExpressionHandler&& other) noexcept
	{
		if (this != &other)
		{
			free();
			moveFrom(std::move(other));
		}

		return *this;
	}

	~BooleanExpressionHandler()
	{
		free();
	}

	bool evaluate(const BooleanInterpretation& bi) const
	{
		return expr->eval(bi);
	}

	bool isTautology() const
	{
		return checkAllTruthAssignments(true);
	}

	bool isContradiction() const
	{
		return checkAllTruthAssignments(false);
	}
};

int main()
{
	BooleanExpressionHandler be("((p)|((q)&(t)))");
	BooleanInterpretation bi;
	bi.set('p', true);
	std::cout << be.evaluate(bi) << std::endl;
	BooleanExpressionHandler be2("((p)|(!(p)))");
	std::cout << be2.isTautology() << std::endl;

	return 0;
}