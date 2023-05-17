// -*- mode: c++ -*-

/***** Auto generated file: DO NOT EDIT !!!!!! *****/
/*** Generated at: Wed 17 May-2023 03:29:06  ***/
/*** Generated from config\logging.xml **/
/*** Validated by config\logging.xsd **/

/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/
/*****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) Per Thomas Hille <pth@embc.no>  http:///www.embc.no      ***
*** all rights reserved                                                    ***
***                                                                        ***
*** logmaster is free software: you can redistribute it and/or modify      ***
*** it under the terms of the Lesser GNU General Public License (LGPL)     ***
*** as published by the Free Software Foundation, either version 3 of the  ***
*** License, or (at your option) any later version.                        ***
***                                                                        ***
*** logmaster is distributed in the hope that it will be useful,           ***
*** but WITHOUT ANY WARRANTY; without even the implied warranty of         ***
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          ***
*** GNU General Public License for more details.                           ***
***                                                                        ***
*** You should have received a copy of the Lesser GNU General Public       ***
*** License along with logmaster in the README file in the source code     ***
*** directory. If not, see <http://www.gnu.org/licenses/>.                 ***
******************************************************************************
******************************************************************************/

EXCEPTION_CLASS_H	(GFsmException)
EXCEPTION_CLASS_CPP	(GFsmException)
EXCEPTION_CLASS_H	(GMessageException)
EXCEPTION_CLASS_CPP	(GMessageException)
EXCEPTION_CLASS_H	(GComException)
EXCEPTION_CLASS_CPP	(GComException)
EXCEPTION_CLASS_H	(GXmlException)
EXCEPTION_CLASS_CPP	(GXmlException)
EXCEPTION_CLASS_H	(GDatabaseException)
EXCEPTION_CLASS_CPP	(GDatabaseException)
EXCEPTION_CLASS_H	(GUserException)
EXCEPTION_CLASS_CPP	(GUserException)
EXCEPTION_CLASS_H	(GGeneralException)
EXCEPTION_CLASS_CPP	(GGeneralException)
EXCEPTION_CLASS_H	(GAlarmException)
EXCEPTION_CLASS_CPP	(GAlarmException)



#define FSM_EXCEPTION(...)			throw_exception( GFsmException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_FSM,	__VA_ARGS__ ) )
#define MESSAGE_EXCEPTION(...)			throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_MESSAGE,	__VA_ARGS__ ) )
#define MSG_EXCEPTION(...)			throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_MESSAGE,	__VA_ARGS__ ) )
#define COM_EXCEPTION(...)			throw_exception( GComException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_COM,	__VA_ARGS__ ) )
#define XML_EXCEPTION(...)			throw_exception( GXmlException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_XML,	__VA_ARGS__ ) )
#define DATABASE_EXCEPTION(...)			throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_DATABASE,	__VA_ARGS__ ) )
#define DB_EXCEPTION(...)			throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_DATABASE,	__VA_ARGS__ ) )
#define USER_EXCEPTION(...)			throw_exception( GUserException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_USER,	__VA_ARGS__ ) )
#define USR_EXCEPTION(...)			throw_exception( GUserException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_USER,	__VA_ARGS__ ) )
#define GENERAL_EXCEPTION(...)			throw_exception( GGeneralException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_GENERAL,	__VA_ARGS__ ) )
#define G_EXCEPTION(...)			throw_exception( GGeneralException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_GENERAL,	__VA_ARGS__ ) )
#define ALARM_EXCEPTION(...)			throw_exception( GAlarmException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_ALARM,	__VA_ARGS__ ) )


#define FSM_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GFsmException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_FSM),	__VA_ARGS__ ) )
#define MESSAGE_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_MESSAGE),	__VA_ARGS__ ) )
#define MSG_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_MESSAGE),	__VA_ARGS__ ) )
#define COM_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GComException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_COM),	__VA_ARGS__ ) )
#define XML_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GXmlException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_XML),	__VA_ARGS__ ) )
#define DATABASE_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_DATABASE),	__VA_ARGS__ ) )
#define DB_ASSERT_EXCEPTION(expr,  ...)		 if(!(expr)) throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_DATABASE),	__VA_ARGS__ ) )
#define USER_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GUserException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_USER),	__VA_ARGS__ ) )
#define USR_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GUserException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_USER),	__VA_ARGS__ ) )
#define GENERAL_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GGeneralException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_GENERAL),	__VA_ARGS__ ) )
#define G_ASSERT_EXCEPTION(expr,  ...)		 if(!(expr)) throw_exception( GGeneralException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_GENERAL),	__VA_ARGS__ ) )
#define ALARM_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GAlarmException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_ALARM),	__VA_ARGS__ ) )



