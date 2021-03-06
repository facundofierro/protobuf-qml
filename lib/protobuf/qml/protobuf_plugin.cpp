#include "protobuf/qml/protobuf_plugin.h"
#include "protobuf/qml/descriptors.h"
#include "protobuf/qml/memory.h"
#include "protobuf/qml/file.h"
#include "protobuf/qml/method.h"
#include "protobuf/qml/server_method.h"
#include <QObject>
#include <QtQml>

QObject* descriptorPoolFactory(QQmlEngine*, QJSEngine*) {
  return new protobuf::qml::DescriptorPoolWrapper;
}

void ProtobufQmlPlugin::registerTypes(const char* uri) {
  qmlRegisterSingletonType<protobuf::qml::DescriptorPoolWrapper>(
      uri, 1, 0, "DescriptorPool", descriptorPoolFactory);
  qmlRegisterUncreatableType<protobuf::qml::FileDescriptorWrapper>(
      uri, 1, 0, "FileDescriptor", "FileDescriptor is abstract type.");
  qmlRegisterUncreatableType<protobuf::qml::DescriptorWrapper>(
      uri, 1, 0, "Descriptor", "Descriptor is abstract type.");
  qmlRegisterUncreatableType<protobuf::qml::Descriptor>(
      uri, 1, 0, "V4Descriptor", "Descriptor is abstract type.");
  qmlRegisterUncreatableType<protobuf::qml::StatusCode>(
      uri, 1, 0, "StatusCode", "StatusCode is enum holder.");

  // buffers
  qmlRegisterType<protobuf::qml::MemoryBufferChannel>(uri, 1, 0,
                                                      "MemoryBufferChannel");
  qmlRegisterType<protobuf::qml::FileChannel>(uri, 1, 0, "FileChannel");

  // client
  qmlRegisterType<protobuf::qml::Channel2>(uri, 1, 0, "Channel2");
  qmlRegisterType<protobuf::qml::UnaryMethodHolder>(uri, 1, 0,
                                                    "UnaryMethodHolder");
  qmlRegisterType<protobuf::qml::WriterMethodHolder>(uri, 1, 0,
                                                     "WriterMethodHolder");
  qmlRegisterType<protobuf::qml::ReaderMethodHolder>(uri, 1, 0,
                                                     "ReaderMethodHolder");
  qmlRegisterType<protobuf::qml::ReaderWriterMethodHolder>(
      uri, 1, 0, "ReaderWriterMethodHolder");

  // server
  qmlRegisterType<protobuf::qml::RpcServer>(uri, 1, 0, "RpcServer");
  qmlRegisterType<protobuf::qml::RpcService>(uri, 1, 0, "RpcService");
  qmlRegisterType<protobuf::qml::ServerUnaryMethodHolder>(
      uri, 1, 0, "ServerUnaryMethodHolder");
  qmlRegisterType<protobuf::qml::ServerReaderMethodHolder>(
      uri, 1, 0, "ServerReaderMethodHolder");
  qmlRegisterType<protobuf::qml::ServerWriterMethodHolder>(
      uri, 1, 0, "ServerWriterMethodHolder");
  qmlRegisterType<protobuf::qml::ServerReaderWriterMethodHolder>(
      uri, 1, 0, "ServerReaderWriterMethodHolder");
}
