/*
 * (C) 2009 Nikhil Marathe <nsm.nikhil@gmail.com>
 * Licensed under the GNU General Public License.
 * See LICENSE for details
 */
#include "memberutils.h"

QHash<QString, QHash<QString, Member*> > MemberUtils::m_hash;

void MemberUtils::init()
{
}

void MemberUtils::insert(QString group, Member* m)
{
    m_hash[group][m->addressString()] = m ;
}

bool MemberUtils::contains(QString group, Member* m)
{
    return m_hash[group].contains(m->addressString());
}

/*
 * Returns the Member* within the set. This means
 * you can construct fake Member* with only the IP
 * to get full details of the member if available.
 * Unless you need custom behaviour, use MemberUtils::get(QString, QString)
 */
Member* MemberUtils::get(QString group, Member* m)
{
    return m_hash[group].value(m->addressString());
}

Member* MemberUtils::get(QString group, QString ip)
{
    Member* m = new Member;
    m->setAddress(ip);
    return get(group, m);
}

void MemberUtils::remove(QString group, Member* m)
{
    m_hash[group].remove(m->addressString());
}

void MemberUtils::remove(QString group, QString ip)
{
    Member* m = new Member;
    m->setAddress(ip);
    remove(group, m);
}