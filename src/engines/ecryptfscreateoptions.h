/*
 *
 *  Copyright (c) 2017
 *  name : Francis Banyikwa
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ECRYPTFSCREATEOPTIONS_H
#define ECRYPTFSCREATEOPTIONS_H

#include <functional>
#include <utility>

#include <QCloseEvent>
#include <QString>
#include <QDialog>

#include "../engines.h"

namespace Ui {
class ecryptfscreateoptions;
}

class ecryptfscreateoptions : public QDialog
{
	Q_OBJECT
public:
	static QString defaultCreateOptions()
	{
		return "-o key=passphrase,ecryptfs_key_bytes=32,ecryptfs_cipher=aes,ecryptfs_passthrough=n,ecryptfs_enable_filename_crypto=y" ;
	}
	static QString defaultMiniCreateOptions()
	{
		return "-o key=passphrase,ecryptfs_key_bytes=32,ecryptfs_cipher=aes" ;
	}
	static void instance( QWidget * parent,engines::engine::fCreateOptions function )
	{
                new ecryptfscreateoptions( parent,std::move( function ) ) ;
	}
	ecryptfscreateoptions( QWidget * parent,engines::engine::fCreateOptions ) ;
        ~ecryptfscreateoptions() ;
private slots:
	void pbSelectConfigPath() ;
	void pbOK() ;
	void pbCancel() ;
private:
	void HideUI( const engines::engine::createOptions& = engines::engine::createOptions() ) ;
	void closeEvent( QCloseEvent * ) ;
        Ui::ecryptfscreateoptions * m_ui ;
	engines::engine::fCreateOptions m_function ;
};

#endif // ECRYPTFSCREATEOPTIONS_H
