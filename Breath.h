#pragma once
class Breath
{
	friend class Cabnet;

private://can not be accesed
	int 
		breath;

public:
	Breath(void);
	~Breath(void);

	void DoYourBest(int &breath);
	void Pass(int &breath);
	void Faile();
};

