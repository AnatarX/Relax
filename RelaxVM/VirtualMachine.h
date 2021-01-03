#pragma once
#include <QtCore>

#include "../Libs/ByteArrayLib.h"
#include "../Libs/ConsoleTextStream.h"
#include "Exceptions/ExitException.h"
#include "Functions/Exit.h"
#include "Class.h"
#include "Instruction.h"

class VirtualMachine
{
public:
	VirtualMachine(const QStringList& argv);
	~VirtualMachine();
	void Start();
	void ProcessInstruction(Instruction instruction);

private:
	QStringList arguments;
	QString filename;
	QFile executableFile;
	Class* mainClass;
};

