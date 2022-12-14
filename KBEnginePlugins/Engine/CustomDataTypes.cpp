#include "CustomDataTypes.h"
#include "EntityDef.h"
#include "KBDebug.h"
#include "DataTypes.h"
#include "Runtime/Core/Public/Misc/Variant.h"

namespace KBEngine
{

void DATATYPE_CHAI_INFO::createFromStreamEx(MemoryStream& stream, CHAI_INFO& datas)
{
	datas.Name = stream.readUnicode();
	datas.Time = stream.readUnicode();
	datas.Msg = stream.readUnicode();
}

void DATATYPE_CHAI_INFO::addToStreamEx(Bundle& stream, const CHAI_INFO& v)
{
	stream.writeUnicode(v.Name);
	stream.writeUnicode(v.Time);
	stream.writeUnicode(v.Msg);
}


}