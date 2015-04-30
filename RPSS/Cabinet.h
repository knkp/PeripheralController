#pragma once
class Cabinet
{
	friend class Breath;

	private://can not be accesed
	int
		lock,
		unlock,
		breath;

public:
	Cabinet(void);
	~Cabinet(void);

	void Check(int &breath);
	void Open();
	void Closed();
	void Basket();
};

