// nodes.h
// Neural Interfaces

#ifndef NODES_H
#define NODES_H

#include <string>
#include "cores.h"

class ProcessorNode // Register
{
	
	private:
		std::string name;
		DataCore core;
		
	public:
		ProcessorNode ();
		ProcessorNode (std::string name);
			
		DataCore getCore ();
		std::string getName ();
		
		void setCore (DataCore core);
		void setData (int data);
		int getData ();
		
}; // End Neural Interfaces

#endif

