//
//  CentralWidget.hpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 23/04/2018.
//

#ifndef CentralWidget_hpp
#define CentralWidget_hpp

#include <QWidget>

#include <QHBoxLayout>
#include <QScrollBar>

#include "TreeView.hpp"

#include "GraphicsView.hpp"
#include "GraphicsScene.hpp"

#include <QTextEdit>

#include "GlobalDatabase.hpp"

#include "EditorWindow.hpp"



// NOW, WHAT IF MY CENTRAL WIDGET NEEDS TO DO STUFF ON A MAINWINDOW?
// OBVIOUSLY WON'T INCLUDE, BUT FORWARD DECLARE




class CentralWidget : public QWidget
{
    Q_OBJECT
    
public:
    CentralWidget(QWidget *parent, GlobalDataBase *refDatabase);
    ~CentralWidget();
    
    TreeView *getFileExplorer() const;
    GraphicsView *getView() const;
    GraphicsScene *getScene() const;
    QTextEdit *getObjectInspector() const;
    
    bool isFileExplorerHidden() const;
    bool isObjectInspectorHidden() const;
    
    void setIsFileExplorerHidden(bool hidden);
    void setIsObjectInspectorHidden(bool hidden);
    
    void resizeEvent(QResizeEvent *event) override;

    
    GlobalDataBase *database;
    
    EditorWindow *editorWindow;
    
    
private:
    QHBoxLayout *layout;
    bool fileExplorerIsHidden;
    bool objectInspectorIsHidden;
    
    TreeView *fileExplorer;
    
    GraphicsView *view;
    GraphicsScene *scene;
    
    QTextEdit *objectInspector;
};





#endif /* CentralWidget_hpp */
