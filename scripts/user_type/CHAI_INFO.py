# -*- coding: utf-8 -*-
import KBEngine
from KBEDebug import *

class TChatInfo(dict):
    def __init__(self):
        dict.__init__(self)

    def asDict(self):
        return {"Name": self["Name"], "Time": self["Time"], "Msg" : self["Msg"]}

    def createFromDict(self,DictData):
        self["Name"] = DictData["Name"]
        self["Time"] = DictData["Time"]
        self["Msg"] = DictData["Msg"]
        return self

class CHAI_INFO_PICKLER:
    def __init__(self):
        pass

    def createObjFromDict(self, dct):

        return TChatInfo().createFromDict(dict)

        """
        从一个dict创建一个对应的object
        此接口被C + +底层调用
        底层需要从脚本层中获取数据，脚本层此时应该将数据结构还原为固定字典
        list([0, 0]) = > {"k1": 0, "k2": 0}
        """

    def getDictFromObj(self, obj):
        """
        从一个object创建一个对应dict
        """
        return obj.asDict()


    def isSameType(self, obj):
        """
        是否同类型
        """

        return isinstance(obj, TChatInfo)

ChatInfoInst = CHAI_INFO_PICKLER()