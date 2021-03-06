#include "StdClass.h"

StdClass::StdClass(const QString& name, const QList<StdMethod>& methods)
	:name(name), methods(methods)
{

}

QString StdClass::GetName() const
{
	return name;
}

QList<StdMethod> StdClass::GetMethods() const
{
	return methods;
}

StdMethod* StdClass::GetMethod(const MethodSignature& signature)
{
	auto methodIterator = std::find_if(methods.begin(), methods.end(), [&](const StdMethod& method) {
		return signature == dynamic_cast<const MethodSignature&>(method);
	});
	if(methodIterator == methods.end())
		return nullptr;
	return &(*methodIterator);
}

StdMethod* StdClass::GetMethod(const QString& name, const QString& dataType, const QList<Parameter>& parameters)
{
	auto methodIterator = std::find_if(methods.begin(), methods.end(), [&](const StdMethod& method) {
		bool nameIsEqual = name == method.GetName();
		bool dataTypeIsEqual = dataType == method.GetDataType();
		bool parametersIsEqual = parameters == method.GetParameters();
		return nameIsEqual && dataTypeIsEqual && parametersIsEqual;
	});
	if (methodIterator == methods.end())
		return nullptr;
	return &(*methodIterator);
}

StdMethod* StdClass::GetMethod(int index)
{
	if(methods.size() > index)
		return nullptr;
	return &(methods[index]);
}

void StdClass::SetName(const QString& name)
{
	this->name = name;
}

void StdClass::SetMethods(const QList<StdMethod>& methods)
{
	this->methods = methods;
}

void StdClass::SetMethod(int index, const StdMethod& method)
{
	methods[index] = method;
}
