int main()
{
	if(E1)
	{
		S1;
		S2;
		S3;
	}
	else
	{
		S4;
		if(E2)
		{
			S2;
			S3;
		}
		else
		{
			S5;
			if(E3)
			{
				S3;
			}
			else
			{
				S6;
			}
		}
	}
	return 0;
}