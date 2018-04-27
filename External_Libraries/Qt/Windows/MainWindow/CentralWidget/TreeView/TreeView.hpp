//
//  TreeView.hpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 23/04/2018.
//

#ifndef TreeView_hpp
#define TreeView_hpp

#include <QTreeView>
#include <QWidget>

class TreeView : public QTreeView
{
    Q_OBJECT

public:
    
    TreeView(QWidget *parent);
    ~TreeView();
    
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    
private:
    QModelIndex clickedIndex;
    QString clickedFileName;
    QString clickedFilePath;
    QPointF dragStartPosition;
};

#endif /* TreeView_hpp */
