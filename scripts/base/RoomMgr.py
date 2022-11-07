# -*- coding: utf-8 -*-
import KBEngine
from KBEDebug import *

class RoomMgr(KBEngine.Entity):
    def __init__(self):
        KBEngine.Entity.__init__(self)
        KBEngine.globalData["RoomMgr"] = self

        self.RoomDict = {}

        self.CreateRoom("房间_1", 10)
        self.CreateRoom("房间_2", 20)

    def CreateRoom(self, Name, Count):
        """
        创建房间
        """
        for RoomName, Room in self.RoomDict.items():
            if RoomName is Name:
                return

        Props = {"Name": Name, "Count": Count}
        KBEngine.createEntityLocally("SRoom", Props)


    def EnterRoom(self, Name, EntityCall):
        """
        请求进入房间
        ；param Name:房间名

        """
        Room = self.RoomDict[Name]
        if Room is None:
            DEBUG_MSG("RoomMgr Enter %s Failed" % Name)
            return
        
        Room.Enter(EntityCall)

    def LeaveRoom(self,EntityId,Name):
        """

        请求离开房间
        ：param EntityId: 请求者ID
        """
        Room = self.RoomDict[Name]
        if Room is None:
            DEBUG_MSG("RoomMgr Enter %s Failed" % Name)
            return
        Room.leave(EntityId)

    def OnRoomGetCell(self, Room):

        """
        创建房间Cell实体成功回调函数
        ：param Room:
        ；retutn :
        """
        self.RoomDict[Room.Name] = Room

    def OnRoomLoseCell(self, Name):

        """
        销毁房间Cell实体后回调函数
        ：param Name: 房间名
        """
        del self.RoomDict[Name]
