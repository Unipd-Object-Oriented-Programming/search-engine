QT += core widgets
CONFIG += debug

HEADERS += \
    Service/Logger/Level.h \
    Service/Logger/AbstractLogger.h \
    Service/Logger/Stream.h \
    Service/Logger/MinimumLevel.h \
    Service/Logger/Composite.h \
    Service/Logger/Singleton.h \
    Service/Logger/Facade.h \
    Service/Container.h \
    \
    Service/StringFilter.h \
    \
    Item/AbstractItem.h \
    Item/WebPage.h \
    Item/AbstractProduct.h \
    Item/Simple.h \
    Item/Virtual.h \
    Item/Bundle.h \
    Item/IConstVisitor.h \
    Item/IVisitor.h \
    \
    Item/Converter/Json/Json.h \
    Item/Converter/Json/JsonVisitor.h \
    Item/Converter/Json/IReader.h \
    Item/Converter/Json/Reader.h \
    \
    Item/DataMapper/JsonFile.h \
    \
    Item/Repository/IRepository.h \
    Item/Repository/JsonRepository.h \
    \
    Engine/Query.h \
    Engine/ItemDecorator.h \
    Engine/ResultSet.h \
    Engine/ScoreVisitor.h \
    Engine/FilterVisitor.h \
    Engine/Memory.h \
    \
    View/WidgetLookup.h \
    View/MainWindow.h \
    View/SearchWidget.h \
    View/ResultsWidget.h \
    View/TypeSelector.h \
    View/EditWidget.h \
    \
    View/ItemRenderer/IItemRenderer.h \
    View/ItemRenderer/ListItem.h \
    View/ItemRenderer/Card.h \
    View/ItemRenderer/Teaser.h \
    View/ItemRenderer/Full.h \
    \
    View/ItemEditor/AbstractItemEditor.h \
    View/ItemEditor/WebPageEditor.h \
    View/ItemEditor/SimpleEditor.h \
    View/ItemEditor/VirtualEditor.h \
    View/ItemEditor/BundleEditor.h \
    View/ItemEditor/ItemSelectorWidget.h \
    View/ItemEditor/ItemInjector.h \
    \
    View/ResultRenderer/IResultRendererStrategy.h \
    View/ResultRenderer/List.h \
    View/ResultRenderer/Grid.h \
    View/ResultRenderer/Hero.h

SOURCES += \
    Service/Logger/AbstractLogger.cpp \
    Service/Logger/Stream.cpp \
    Service/Logger/MinimumLevel.cpp \
    Service/Logger/Composite.cpp \
    Service/Logger/Singleton.cpp \
    Service/Logger/Facade.cpp \
    \
    Service/StringFilter.cpp \
    \
    Item/AbstractItem.cpp \
    Item/WebPage.cpp \
    Item/AbstractProduct.cpp \
    Item/Simple.cpp \
    Item/Virtual.cpp \
    Item/Bundle.cpp \
    \
    Item/Converter/Json/Json.cpp \
    Item/Converter/Json/JsonVisitor.cpp \
    Item/Converter/Json/Reader.cpp \
    \
    Item/DataMapper/JsonFile.cpp \
    \
    Item/Repository/JsonRepository.cpp \
    \
    Engine/Query.cpp \
    Engine/ItemDecorator.cpp \
    Engine/ResultSet.cpp \
    Engine/ScoreVisitor.cpp \
    Engine/FilterVisitor.cpp \
    Engine/Memory.cpp \
    \
    View/WidgetLookup.cpp \
    View/MainWindow.cpp \
    View/SearchWidget.cpp \
    View/ResultsWidget.cpp \
    View/TypeSelector.cpp \
    View/EditWidget.cpp \
    \
    View/ItemRenderer/ListItem.cpp \
    View/ItemRenderer/Card.cpp \
    View/ItemRenderer/Teaser.cpp \
    View/ItemRenderer/Full.cpp \
    \
    View/ItemEditor/AbstractItemEditor.cpp \
    View/ItemEditor/WebPageEditor.cpp \
    View/ItemEditor/SimpleEditor.cpp \
    View/ItemEditor/VirtualEditor.cpp \
    View/ItemEditor/BundleEditor.cpp \
    View/ItemEditor/ItemSelectorWidget.cpp \
    View/ItemEditor/ItemInjector.cpp \
    \
    View/ResultRenderer/List.cpp \
    View/ResultRenderer/Grid.cpp \
    View/ResultRenderer/Hero.cpp \
    \
    main.cpp

RESOURCES += \
    resources.qrc

TARGET = SearchEngine
