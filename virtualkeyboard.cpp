#include "virtualkeyboard.h"
#include "ui_virtualkeyboard.h"
#include "mykeypressevent.h"
#include <QWidget>
#include <QDebug>

bool capsLock = false;
VirtualKeyboard::VirtualKeyboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VirtualKeyboard)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Popup);
}

bool VirtualKeyboard::event(QEvent *event){


    return QWidget::event(event);
}

VirtualKeyboard::~VirtualKeyboard()
{
    delete ui;
}



void VirtualKeyboard::init(){



}

void VirtualKeyboard::postEvent(QString str)
{
    QWidget *receiver = QApplication::focusWidget();

    MyKeyPressEvent *sendCustomerEvent = new MyKeyPressEvent(str);
    bool result = QCoreApplication::sendEvent(receiver, sendCustomerEvent);

    Q_ASSERT(result);

    delete sendCustomerEvent;
}

void VirtualKeyboard::on_pushButton_wenhao_clicked()
{
    postEvent(ui->pushButton_wenhao->text());
}

void VirtualKeyboard::on_pushButton_esc_clicked()
{

    postEvent(ui->pushButton_esc->text());
}

void VirtualKeyboard::on_pushButton_1_clicked()
{

    postEvent(ui->pushButton_1->text());
}

void VirtualKeyboard::on_pushButton_2_clicked()
{

    postEvent(ui->pushButton_2->text());
}

void VirtualKeyboard::on_pushButton_3_clicked()
{

    postEvent(ui->pushButton_3->text());
}

void VirtualKeyboard::on_pushButton_4_clicked()
{

    postEvent(ui->pushButton_4->text());
}

void VirtualKeyboard::on_pushButton_5_clicked()
{

    postEvent(ui->pushButton_5->text());
}

void VirtualKeyboard::on_pushButton_6_clicked()
{

    postEvent(ui->pushButton_6->text());
}

void VirtualKeyboard::on_pushButton_7_clicked()
{

    postEvent(ui->pushButton_7->text());
}

void VirtualKeyboard::on_pushButton_8_clicked()
{

    postEvent(ui->pushButton_8->text());
}

void VirtualKeyboard::on_pushButton_9_clicked()
{

    postEvent(ui->pushButton_9->text());
}

void VirtualKeyboard::on_pushButton_0_clicked()
{

    postEvent(ui->pushButton_0->text());
}

void VirtualKeyboard::on_pushButton_del_clicked()
{

    postEvent("backspace");
}

void VirtualKeyboard::on_pushButton_at_clicked()
{

    postEvent(ui->pushButton_at->text());
}

void VirtualKeyboard::on_pushButton_q_clicked()
{

    postEvent(ui->pushButton_q->text());
}

void VirtualKeyboard::on_pushButton_w_clicked()
{

    postEvent(ui->pushButton_w->text());
}

void VirtualKeyboard::on_pushButton_e_clicked()
{

    postEvent(ui->pushButton_e->text());
}

void VirtualKeyboard::on_pushButton_r_clicked()
{

    postEvent(ui->pushButton_r->text());
}

void VirtualKeyboard::on_pushButton_t_clicked()
{

    postEvent(ui->pushButton_t->text());
}

void VirtualKeyboard::on_pushButton_y_clicked()
{

    postEvent(ui->pushButton_y->text());
}

void VirtualKeyboard::on_pushButton_u_clicked()
{

    postEvent(ui->pushButton_u->text());
}

void VirtualKeyboard::on_pushButton_i_clicked()
{

    postEvent(ui->pushButton_i->text());
}

void VirtualKeyboard::on_pushButton_o_clicked()
{

    postEvent(ui->pushButton_o->text());
}

void VirtualKeyboard::on_pushButton_p_clicked()
{

    postEvent(ui->pushButton_p->text());
}

void VirtualKeyboard::on_pushButton_maohao_clicked()
{

    postEvent(ui->pushButton_maohao->text());
}

void VirtualKeyboard::on_pushButton_yinhao_clicked()
{

    postEvent( ui->pushButton_yinhao->text());
}

void VirtualKeyboard::on_pushButton_switchletter_clicked()
{
    capsLock = !capsLock;
    if(capsLock){
        ui->pushButton_a->setText("A");
        ui->pushButton_b->setText("B");
        ui->pushButton_c->setText("C");
        ui->pushButton_d->setText("D");
        ui->pushButton_e->setText("E");
        ui->pushButton_f->setText("F");
        ui->pushButton_g->setText("G");
        ui->pushButton_h->setText("H");
        ui->pushButton_i->setText("I");
        ui->pushButton_j->setText("J");
        ui->pushButton_k->setText("K");
        ui->pushButton_l->setText("L");
        ui->pushButton_m->setText("M");
        ui->pushButton_n->setText("N");
        ui->pushButton_o->setText("O");
        ui->pushButton_p->setText("P");
        ui->pushButton_q->setText("Q");
        ui->pushButton_r->setText("R");
        ui->pushButton_s->setText("S");
        ui->pushButton_t->setText("T");
        ui->pushButton_u->setText("U");
        ui->pushButton_v->setText("V");
        ui->pushButton_w->setText("W");
        ui->pushButton_x->setText("X");
        ui->pushButton_y->setText("Y");
        ui->pushButton_z->setText("Z");
    }else {
        ui->pushButton_a->setText("a");
        ui->pushButton_b->setText("b");
        ui->pushButton_c->setText("c");
        ui->pushButton_d->setText("d");
        ui->pushButton_e->setText("e");
        ui->pushButton_f->setText("f");
        ui->pushButton_g->setText("g");
        ui->pushButton_h->setText("h");
        ui->pushButton_i->setText("i");
        ui->pushButton_j->setText("j");
        ui->pushButton_k->setText("k");
        ui->pushButton_l->setText("l");
        ui->pushButton_m->setText("m");
        ui->pushButton_n->setText("n");
        ui->pushButton_o->setText("o");
        ui->pushButton_p->setText("p");
        ui->pushButton_q->setText("q");
        ui->pushButton_r->setText("r");
        ui->pushButton_s->setText("s");
        ui->pushButton_t->setText("t");
        ui->pushButton_u->setText("u");
        ui->pushButton_v->setText("v");
        ui->pushButton_w->setText("w");
        ui->pushButton_x->setText("x");
        ui->pushButton_y->setText("y");
        ui->pushButton_z->setText("z");
    }

}

void VirtualKeyboard::on_pushButton_a_clicked()
{
    postEvent(ui->pushButton_a->text());
}

void VirtualKeyboard::on_pushButton_s_clicked()
{
    postEvent(ui->pushButton_s->text());
}

void VirtualKeyboard::on_pushButton_d_clicked()
{
    postEvent(ui->pushButton_d->text());
}

void VirtualKeyboard::on_pushButton_f_clicked()
{
    postEvent(ui->pushButton_f->text());
}

void VirtualKeyboard::on_pushButton_g_clicked()
{
    postEvent(ui->pushButton_g->text());
}

void VirtualKeyboard::on_pushButton_h_clicked()
{
    postEvent(ui->pushButton_h->text());
}

void VirtualKeyboard::on_pushButton_j_clicked()
{
    postEvent(ui->pushButton_j->text());
}

void VirtualKeyboard::on_pushButton_k_clicked()
{
    postEvent(ui->pushButton_k->text());
}

void VirtualKeyboard::on_pushButton_l_clicked()
{
    postEvent(ui->pushButton_l->text());
}

void VirtualKeyboard::on_pushButton_xiahuaxian_clicked()
{
    postEvent(ui->pushButton_xiahuaxian->text());
}

void VirtualKeyboard::on_pushButton_gang_clicked()
{
    postEvent(ui->pushButton_gang->text());
}

void VirtualKeyboard::on_pushButton_fanxiexian_clicked()
{
    postEvent(ui->pushButton_fanxiexian->text());
}

void VirtualKeyboard::on_pushButton_doller_clicked()
{
    postEvent(ui->pushButton_doller->text());
}

void VirtualKeyboard::on_pushButton_baifenhao_clicked()
{
    postEvent(ui->pushButton_baifenhao->text());
}

void VirtualKeyboard::on_pushButton_z_clicked()
{
    postEvent(ui->pushButton_z->text());
}

void VirtualKeyboard::on_pushButton_x_clicked()
{
    postEvent(ui->pushButton_x->text());
}

void VirtualKeyboard::on_pushButton_c_clicked()
{
    postEvent(ui->pushButton_c->text());
}

void VirtualKeyboard::on_pushButton_v_clicked()
{
    postEvent(ui->pushButton_v->text());
}

void VirtualKeyboard::on_pushButton_b_clicked()
{
    postEvent(ui->pushButton_b->text());
}

void VirtualKeyboard::on_pushButton_n_clicked()
{
    postEvent(ui->pushButton_n->text());
}

void VirtualKeyboard::on_pushButton_m_clicked()
{
    postEvent(ui->pushButton_m->text());
}

void VirtualKeyboard::on_pushButton_gantanhao_clicked()
{
    postEvent(ui->pushButton_gantanhao->text());
}

void VirtualKeyboard::on_pushButton_dot_clicked()
{
    postEvent(ui->pushButton_dot->text());
}

void VirtualKeyboard::on_pushButton_douhao_clicked()
{
    postEvent(ui->pushButton_douhao->text());
}

void VirtualKeyboard::on_pushButton_jinghao_clicked()
{
    postEvent(ui->pushButton_jinghao->text());
}

void VirtualKeyboard::on_pushButton_qiehao_clicked()
{
    postEvent(ui->pushButton_qiehao->text());
}

void VirtualKeyboard::on_pushButton_xinghao_clicked()
{
    postEvent(ui->pushButton_xinghao->text());
}

void VirtualKeyboard::on_pushButton_denghao_clicked()
{
    postEvent(ui->pushButton_denghao->text());
}

void VirtualKeyboard::on_pushButton_space_clicked()
{
    postEvent(ui->pushButton_space->text());
}

void VirtualKeyboard::on_pushButton_guohao1_clicked()
{
    postEvent("(");
}

void VirtualKeyboard::on_pushButton_kuohao2_clicked()
{
    postEvent(")");
}

void VirtualKeyboard::on_pushButton_enter_clicked()
{
    postEvent("enter");
    this->hide();
}
