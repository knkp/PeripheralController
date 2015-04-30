#pragma once
class FingerScanner
{
	friend class Cabnet;
	friend class Breath;

private://can not be accesed
	int 
		scan,
		lock,
		unlock,
		breath;

public:
	FingerScanner(void);
	~FingerScanner(void);

	void Scan(int &scan, int &breath);
	void Stop(int &scan);
	void Go(int &breath);
	void BlackBox();
};

