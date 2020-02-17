#pragma once
#include <string>
#include <iostream>

class DBConnection
{
public:
	DBConnection(std::string strConn) {};
	virtual std::string Type() = 0;

	virtual ~DBConnection(void) {};
};

class SQLDBConnection : public DBConnection
{
public:
	SQLDBConnection(std::string strConn) : DBConnection(strConn) {}

	virtual std::string Type()
	{
		return "SQL";
	}
};

class OracleDBConnection : public DBConnection
{
public:
	OracleDBConnection(std::string strConn) : DBConnection(strConn) {}

	virtual std::string Type()
	{
		return "Oracle";
	}
};

class DBCommand
{
public:
	DBCommand(std::string strCmd) {}
	virtual bool Excute(DBConnection* dc) = 0;
	virtual ~DBCommand(void) {};
};

class SQLDBCommand : public DBCommand
{
public:
	SQLDBCommand(std::string strCmd) : DBCommand(strCmd) {}
	virtual bool Excute(DBConnection* dc)
	{
		if("SQL" != dc->Type())
		{
			std::cout << "not compatible connection!" << std::endl;
			return false;
		}
		std::cout << "sql command excuted!" << std::endl;
		return true;
	}
};

class OracleDBCommand : public DBCommand
{
public:
	OracleDBCommand(std::string strCmd) : DBCommand(strCmd) {}
	virtual bool Excute(DBConnection* dc)
	{
		if("Oracle" != dc->Type())
		{
			std::cout << "not compatible connection!" << std::endl;
			return false;
		}
		std::cout << "oracle command excuted!" << std::endl;
		return true;
	}
};