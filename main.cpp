#include <QPluginLoader>
#include <iostream>


std::string value_to_string(const QJsonValue &value)
{
    switch (value.type()) {
    case QJsonValue::Type::Null:
        return "<Null>";
    case QJsonValue::Type::Bool:
        return value.toBool() ? "True" : "False";
    case QJsonValue::Type::Double:
        return std::to_string(value.toDouble());
    case QJsonValue::Type::String:
        return value.toString().toStdString();
    case QJsonValue::Type::Array:
        return "<Array>";
    case QJsonValue::Type::Object:
        return "<Object>";
    case QJsonValue::Type::Undefined:
        return "<Undefined>";
    default:
        return {};
    }
}


int main(int argc, char *argv[])
{
    const QJsonObject metadata = QPluginLoader(argv[1]).metaData();

    std::cout << "has metadata?: " << (metadata.keys().isEmpty() ? "NO" : "YES") << std::endl;
    for (const QString& key : metadata.keys()) {
        std::cout << key.toStdString() << " : " << value_to_string(metadata[key]) << std::endl;
    }
}
