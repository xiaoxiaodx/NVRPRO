#ifndef VIRTUALKEYBOARD_H
#define VIRTUALKEYBOARD_H

#include <QDialog>
#include <QMutex>
#include <QMutexLocker>
#include <QKeyEvent>
namespace Ui {
class VirtualKeyboard;
}

class VirtualKeyboard : public QDialog
{
    Q_OBJECT

public:
    explicit VirtualKeyboard(QWidget *parent = nullptr);
    ~VirtualKeyboard();

protected:
    bool event(QEvent *event);

private slots:
    void on_pushButton_wenhao_clicked();

    void on_pushButton_esc_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_at_clicked();

    void on_pushButton_q_clicked();

    void on_pushButton_w_clicked();

    void on_pushButton_e_clicked();

    void on_pushButton_r_clicked();

    void on_pushButton_t_clicked();

    void on_pushButton_y_clicked();

    void on_pushButton_u_clicked();

    void on_pushButton_i_clicked();

    void on_pushButton_o_clicked();

    void on_pushButton_p_clicked();

    void on_pushButton_maohao_clicked();

    void on_pushButton_yinhao_clicked();

    void on_pushButton_switchletter_clicked();

    void on_pushButton_a_clicked();

    void on_pushButton_s_clicked();

    void on_pushButton_d_clicked();

    void on_pushButton_f_clicked();

    void on_pushButton_g_clicked();

    void on_pushButton_h_clicked();

    void on_pushButton_j_clicked();

    void on_pushButton_k_clicked();

    void on_pushButton_l_clicked();

    void on_pushButton_xiahuaxian_clicked();

    void on_pushButton_gang_clicked();

    void on_pushButton_fanxiexian_clicked();

    void on_pushButton_doller_clicked();

    void on_pushButton_baifenhao_clicked();

    void on_pushButton_z_clicked();

    void on_pushButton_x_clicked();

    void on_pushButton_c_clicked();

    void on_pushButton_v_clicked();

    void on_pushButton_b_clicked();

    void on_pushButton_n_clicked();

    void on_pushButton_m_clicked();

    void on_pushButton_gantanhao_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_douhao_clicked();

    void on_pushButton_jinghao_clicked();

    void on_pushButton_qiehao_clicked();

    void on_pushButton_xinghao_clicked();

    void on_pushButton_denghao_clicked();

    void on_pushButton_space_clicked();

    void on_pushButton_guohao1_clicked();

    void on_pushButton_kuohao2_clicked();

    void on_pushButton_enter_clicked();

private:
   void postEvent(QString str);
   void init();
   Ui::VirtualKeyboard *ui;

};

#endif // VIRTUALKEYBOARD_H
