#ifndef __EXAMPLE__
#define __EXAMPLE__
	
class Example {
		
private:
	
	// (1)
	int data;
	int num;
	static int count;
			
public:
	
	Example(int data);
	void getData();
	~Example();

};
		
#endif