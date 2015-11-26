#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.load(app.applicationDirPath() + "/../examples/WebSockets/client.qml");

  return app.exec();
}
