#include "Screen.h"

Screen::Screen(QWidget* parent = nullptr)
{
    this->setParent(parent);
    const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if (cameras.size() > 0)
    {
        camera = new QCamera(QCameraInfo::defaultCamera(), this);
        viewfinder = new QCameraViewfinder(this);

        layout.addWidget(viewfinder);
        viewfinder->show();
        viewfinder->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        camera->setViewfinder(viewfinder);
        camera->setCaptureMode(QCamera::CaptureVideo);

        setLayout(&layout);
    }
    else
    {
        std::string err{ "No camera has been found" };
        std::cerr << err << '\n';
        qDebug() << QString::fromStdString(err) << '\n';
    }
}

Screen::~Screen()
{
    //to be honest, unneccessary
    camera->stop();
    camera->unload();
}

void Screen::StartRecording()
{
    camera->start();
    viewfinder->setHidden(false);
}

void Screen::StopRecording()
{
    camera->stop();
    viewfinder->setHidden(true);
}
