#pragma once
class Cabnet
{
	friend class Breath;

	private://can not be accesed
	int
		lock,
		unlock,
		breath;

public:
	Cabnet(void);
	~Cabnet(void);

	void Check(int &breath);
	void Open();
	void Closed();
	void Basket();
};

