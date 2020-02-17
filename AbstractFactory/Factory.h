#pragma once
#include "Product.h"

class DBFactory
{
public:
	virtual DBConnection* CreateDBConnection(std::string strConn) = 0;
	virtual DBCommand* CreateDBCommand(std::string strCmd) = 0;
	virtual ~DBFactory(void) {};
};

class SQLDBFactory : public DBFactory
{
public:
	virtual DBConnection* CreateDBConnection(std::string strConn)
	{
		return new SQLDBConnection(strConn);
	}
	virtual DBCommand* CreateDBCommand(std::string strCmd)
	{
		return new SQLDBCommand(strCmd);
	}
};

class OracleDBFactory : public DBFactory
{
public:
	virtual DBConnection* CreateDBConnection(std::string strConn)
	{
		return new OracleDBConnection(strConn);
	}
	virtual DBCommand* CreateDBCommand(std::string strCmd)
	{
		return new OracleDBCommand(strCmd);
	}
};

