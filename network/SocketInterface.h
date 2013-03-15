/*
 * ZSUMMER License
 * -----------
 * 
 * ZSUMMER is licensed under the terms of the MIT license reproduced below.
 * This means that ZSUMMER is free software and can be used for both academic
 * and commercial purposes at absolutely no cost.
 * 
 * 
 * ===============================================================================
 * 
 * Copyright (C) 2012 YaweiZhang <yawei_zhang@foxmail.com>.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * ===============================================================================
 * 
 * (end of COPYRIGHT)
 */


/*
 * AUTHORS:  YaweiZhang <yawei_zhang@foxmail.com>
 * VERSION:  1.0.0
 * PURPOSE:  A lightweight C++ library for network.
 * CREATION: 2010.8.29
 * LCHANGE:  -
 * LICENSE:  Expat/MIT License, See Copyright Notice at the begin of this file.
 */


/*
 *
 * QQ Group: 19811947
 * Web Site: www.zsummer.net
 * mail: yawei_zhang@foxmail.com
 */


/*
 * UPDATES
 *
 "* 2010.8.29  iocp test\n"
 "* 2010.9.24	ʵ��windows���ٽ����ķ�װ\n"
 "* 2010.9.26	ʵ��windows�¶��̵߳ķ�װ\n"
 "* 2010.9.29	���iocp socket close ��Դ�ͷ�\n"
 "* 2010.10.4  �����IOCP�߼���װ�ӿ�\n"
 "* 2010.12.7  �ع�IOCP����Ʒ�װ, �����������ȶ�\n"
 "* -------------- *\n"

 "* 2011.3.15  iocp / epoll project build\n"
 "* 2011.3.19	ʵ�ֿ�ƽ̨�Ļ�����, �ź���, �̰߳�װ��ķ�װ,  ��ƽ̨��ʱ���ȡ ���� ת��С����\n"
 "* 2011.3.22	���ӿ�ƽ̨�������װ�ӿڳ���, CLog ��װ, createdir����, splitstring, selfmemqueue��\n"
 "* 2011.3.23	����������, ȥ��linux c��ȫСд���\n"
 "* 2011.4.1	epollʵ�־������ܲ���, iocp��ֲ���µ�����ӿ���, CLog���û��ζ���\n"
 "* 2011.4.9   ���ܲ������\n"
 "* -------------- *\n"

 "* 2012.4.21 �µķ�װ, ȫ�±�д\n"
 "* 2012.5.7 ���ӿ�ƽ̨��ϵͳ���̼�ؼ�¼ģ��\n"
 "* 2012.5.8  ����minidumpģ��\n"
 "* 2012.5.28 IOCPʵ�����\n"
 "* 2012.6.6 EPOLLʵ�����\n"
 "* 2012.6.7 ��������, ���Է����д\n"
 "* 2012.6.8 asio���Կͻ��˱�д���\n"
 "* 2012.6.9 ����\n"
 "* 2012.7.18 ���ֻ����µ�ѹ���������\n"
 "* 2012.12.16 ��־���ɵ���־�����Ϊ����־��� ����������� ������ɫ��\n"
 "*--------------- *\n"
 *
 */


#ifndef _ZSUMMER_SOCKETINTERFACE_H_
#define _ZSUMMER_SOCKETINTERFACE_H_

namespace zsummer
{
	namespace network
	{
		class ITcpAccept;
		class ITcpSocket;

		class IIOServerCallback
		{
		public:
			virtual bool OnStop() = 0;
			virtual bool OnMsg(void *pUser) = 0;
		};
		class IIOServer
		{
		public:
			IIOServer(){}
			virtual ~IIOServer() {}
			virtual bool Start(IIOServerCallback *cb) = 0;
			virtual void Run() = 0;
			virtual bool Stop() = 0;
			virtual void Post(void *pUser) = 0;
		};


		class ITcpSocketCallback
		{
		public:
			virtual bool OnConnect(bool bConnected) = 0;
			virtual bool OnRecv() = 0;
			virtual bool OnSend() = 0;
			virtual bool OnClose() = 0;
		};

		class ITcpSocket
		{
		public:
			ITcpSocket(){}
			virtual ~ITcpSocket(){}
			virtual bool BindIOServer(IIOServer * ios) = 0;
			virtual bool SetCallback(ITcpSocketCallback * cb) = 0;
			virtual bool DoConnect(const char *ip, unsigned short port) = 0;
			virtual bool DoSend(char * buf, unsigned int len) = 0;
			virtual bool DoRecv(char * buf, unsigned int len) =0;
			virtual bool GetPeerInfo(unsigned int * addr, unsigned short *port)=0;
			virtual bool Close() = 0;
		};

		class ITcpAcceptCallback
		{
		public:
			virtual bool OnAccept(ITcpSocket * s) = 0;
			virtual bool OnClose() = 0;
		};

		class ITcpAccept
		{
		public:
			ITcpAccept(){}
			virtual ~ITcpAccept(){}
			virtual bool BindIOServer(IIOServer * ios) = 0;
			virtual bool SetCallbck(ITcpAcceptCallback * cb) = 0;
			virtual bool OpenAccept(const char * ip, unsigned short port) = 0;
		};


		IIOServer * CreateIOServer();
		void DestroyIOServer(IIOServer * ios);

		ITcpSocket * CreateTcpSocket();
		void DestroyTcpSocket(ITcpSocket * s);

		ITcpAccept * CreateTcpAccept();
		void DestroyTcpAccept(ITcpAccept *s);
	};
};























#endif











