#pragma once



class IFill
{
public:
	virtual void autoFilling(ReturnedData* insertingWord, Dictionaries* dictionaries) = 0;
};


class AutoFill : public IFill
{
public:
	AutoFill();
	void autoFilling(ReturnedData* insertingWord, Dictionaries* dictionaries);
};