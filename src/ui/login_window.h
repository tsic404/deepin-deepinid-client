#pragma once

#include <QtCore/qglobal.h>
#include <QDBusContext>
#include <DMainWindow>

namespace ddc
{
class LoginWindowPrivate;
class LoginWindow: public Dtk::Widget::DMainWindow,
                   protected QDBusContext
{
Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.deepin.deepinid.Client")
public:
    explicit LoginWindow(QWidget *parent = Q_NULLPTR);
    ~LoginWindow() Q_DECL_OVERRIDE;

    bool isLogin() const;
    void setURL(const QString &url);
    void load();

public Q_SLOTS:
    Q_SCRIPTABLE void Register(const QString &clientID,
                               const QString &service,
                               const QString &path,
                               const QString &interface);

    Q_SCRIPTABLE void Authorize(const QString &clientID,
                                const QStringList &scopes,
                                const QString &callback,
                                const QString &state);

    Q_SCRIPTABLE void Logout();

private:
    QScopedPointer<LoginWindowPrivate> dd_ptr;
    Q_DECLARE_PRIVATE_D(qGetPtrHelper(dd_ptr), LoginWindow)
};

}
