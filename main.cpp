#include <QApplication>
#include <QDir>
#include <QDebug>
#include <QtSql>

#include "ddu_kanvas.h"

// Function prototypes
QString getDatabaseIpAddress();
void setApplicationDatabaseConnection( QString ipAddress );

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	// database setting
	QString ipAddress = getDatabaseIpAddress();
	setApplicationDatabaseConnection( ipAddress );

    ddu_kanvas w;
//    w.show();
    w.showFullScreen();
//    w.showMaximized();
    return a.exec();
}

QString getDatabaseIpAddress()
{
	/**
	 * Get application database IP Address from configuration file.
	 * Default configuration file path is ~/.LC_UD_D/local/bin/konfigurasi.txt
	 */

	// default configuration file path
	QString configurationFilePath(
				QDir::homePath() + "/.LC_UD_D/local/bin/konfigurasi.txt");

	qDebug() << "Loading " << configurationFilePath << "...";

	// check file existence
	QFile file( configurationFilePath );
	if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
	{
		// if file does not exist
		qDebug() << configurationFilePath << " not found!";
		exit( 1 );
	}

	// read configuration file
	QTextStream read( &file );
	QString ipAddress = read.readLine();

	return ipAddress;
}

void setApplicationDatabaseConnection( QString ipAddress )
{
	/**
	 * Set application database connection based on given ipAddress
	 */

	// set database configuration
	QSqlDatabase applicationDatabase;
	applicationDatabase = QSqlDatabase::addDatabase( "QPSQL" );
    applicationDatabase.setDatabaseName( "skm_ddu_2014_db" );
    applicationDatabase.setDatabaseName( "skmddu_2014" );
    applicationDatabase.setHostName( ipAddress );
	applicationDatabase.setUserName( "skmddu_db" );
	applicationDatabase.setPassword( "skmddu2014" );
    applicationDatabase.setUserName( "postgres" );
    applicationDatabase.setPassword( "fisikawangarut" );
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
