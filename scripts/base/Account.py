# -*- coding: utf-8 -*-
import KBEngine
from KBEDebug import *

class Account(KBEngine.Proxy):
	def __init__(self):
		KBEngine.Proxy.__init__(self)


	def onClientEnabled(self):
		"""
		该entity被正式激活为可使用，此时entity已经建立了 client对应实体
		"""

		RoomMgr = KBEngine.globalData["RoomMgr"]
		RoomMgr.EnterRoom("房间_1", self)
