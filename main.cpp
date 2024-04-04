#include <QApplication>
#include <QDir>
#include <QDebug>
#include <QtSql>

#include "ddu_kanvas.h"

// Function prototypes
QString getDatabaseIpAddress();
void setApplicationDatabaseConnection();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	// database setting
    setApplicationDatabaseConnection();

    ddu_kanvas w;
//    w.show();
    w.showFullScreen();
//    w.showMaximized();
    return a.exec();
}

void setApplicationDatabaseConnection( )
{
	/**
	 * Set application database connection based on given ipAddress
	 */

    // load configuration from file
    QSettings dbSettingsFile( QString( QDir::homePath() + "/.LC_UD_D/share/.general_configuration.ini" ), QSettings::IniFormat );
    auto dbName =  dbSettingsFile.value( "db_conf/name", QVariant( QString( "skm_ddu_2014_db" ) ) ).toString();
    auto dbHost =  dbSettingsFile.value( "db_conf/host", QVariant( QString( "localhost" ) ) ).toString();
    auto dbUser =  dbSettingsFile.value( "db_conf/username", QVariant( QString( "skmddu_db" ) ) ).toString();
    auto dbPassword =  dbSettingsFile.value( "db_conf/password", QVariant( QString( "skmddu2014" ) ) ).toString();

    // set database configuration
	QSqlDatabase applicationDatabase;
	applicationDatabase = QSqlDatabase::addDatabase( "QPSQL" );
    applicationDatabase.setDatabaseName(dbName);
    applicationDatabase.setHostName( dbHost );
    applicationDatabase.setUserName( dbUser );
    applicationDatabase.setPassword( dbPassword );
    applicationDatabase.setPort( 5432 );

	// database connection validation
	if( !applicationDatabase.open() )
	{
		qDebug() << applicationDatabase.hostName()
				 << "\ndatabase connection error!\n"
				 << applicationDatabase.lastError().text() << endl;
	}
	else
		qDebug() << applicationDatabase.connectionName().append( " connected" )
				 << endl;
}
