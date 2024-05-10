#ifndef WIDGET_H
#define WIDGET_H

#define _WINDOWS_SIZE 1545,930
#define _BUTTON_SIZE 40
#define _BACK_PICTURE 0
#define _NEXT_PICTURE 1

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QFileDialog>
#include <QEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QDialog>

#include <QMouseEvent>
#include <QKeyEvent>
#include <QEvent>

#include <cmath>
#include <fstream>


class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    void self_windows();                                //APP����ͷ��Ϣ
    void set_part();                                    //���Ԫ�ؼ�����
    void connect_signal_slots();                        //�����ź�����ܽӿ�
    void pix_read_show_clone(QString _filepath);        //��ȡչʾ��¡ԭͼ
    void image_setting();                               //qt || opencv ���ڽ��
    void mouse_callback();                              //��ͼ�ص�����
    void revoke_image_line();                           //���غ���
    void WriteFilesDate(QString _FilePath);             //д��txt��λ���ݺ���
    void ReadFilesData(QString _FilePath);              //��ȡtxt��λ���ݺ���
    static void draw_line(int event,int x,int y,int flags,void *userdate);  //������������
private:
    bool eventFilter(QObject *object, QEvent *event);   //���״̬���ٿ⺯��
    void keyPressEvent(QKeyEvent *event);               //��갴���⺯��
    void wheelEvent(QWheelEvent *event);                //��껬���¼�
    void resizeEvent(QResizeEvent *event);              //ȫ��UI�����任
public slots:
    void open_picture();                                //�򿪻����ļ�
    void back_and_next_picture(int _BackOrNext);        //�л�ͼƬ
private:
    static QLabel *VehicleLineBackgroundImage;          //ͼƬ���ڱ���������opencv���ڰ󶨣�
    QPushButton *SelectImage;                           //���ļ���ť��ť
    QPushButton *BackImage;                             //��һ��ͼƬ��ť
    QPushButton *NextImage;                             //��һ��ͼƬ��ť
    QPushButton *Revoke;                                //���ذ�ť
    QFileDialog *ImageFile;                             //�ļ��Ի���
    QLabel *ImageDirsName;                              //ͼƬ���ƶ�̬��ǩ
    QLabel *ImageNumbers;                               //ͼƬ��Ŷ�̬��ǩ
    QLabel *APP_INFO;                                   //���������Ϣ
    QStringList FilesListName;                          //ͼƬ���ƻ��ܼ���
    QString ImageFileDir;                               //ͼƬ����Ŀ¼����
    static QLabel *PointCoordinate;                     //����ʵʱ��ʾ
    static QString ImageName;                           //��̬ͼƬ·��
    int IndexOfSelectedFile;                            //ͼƬ����
    QString SerialNumber;                               //��̬ͼƬ����
    static std::string VehicleWindowName;               //opencvͼƬ�������ƣ��漰���ƺ�����
    QString filePathBackups;                            //ͼƬ·������
};
#endif // WIDGET_H