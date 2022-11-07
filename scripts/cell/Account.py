# -*- coding: utf-8 -*-
import KBEDebug
import KBEngine
from KBEDebug import *
from CHAI_INFO import TChatInfo
import time

class Account(KBEngine.Entity):
    def __init__(self):
        KBEngine.Entity.__init__(self)


    def ESay(self, Msg):
        """
        服务器发送消息
        被客户端调用方法
        """

        DEBUG_MSG("Account[%i] ESay %s" % (self.id, Msg))


        # 客户端调用OnSay方法 发送消息
        Props = {"Name" :"User" + str(self.id),"Time" :  time.strftime("%a %b %d %H:%M:%S %Y", time.localtime()), "Msg" : Msg }
        ChatInfo = TChatInfo().createFromDict(Props)
        self.allClients.OnSay(ChatInfo)
