#ifndef CORES_H
#define CORES_H

class DataCore // The actual Data, Numbers
{
	private:
		int data;
		
	public:
		
		DataCore ();
		DataCore (int data);
		void storeData (int data);
		int getData ();
	
}; // End Datacore

#endif
