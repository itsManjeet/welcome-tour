#include "window.hh"

#include "config.h"

Window::Window(Gtk::ApplicationWindow::BaseObjectType* cobject,
               Glib::RefPtr<Gtk::Builder> const& builder)
    : Gtk::ApplicationWindow(cobject),
      m_Builder(builder),
      m_FinishBtn(nullptr) {
  m_Settings = Gio::Settings::create(APP_ID);

  builder->get_widget("finish_btn", m_FinishBtn);

  m_FinishBtn->signal_clicked().connect(
      sigc::mem_fun(this, &Window::on_finish_btn_clicked));
  set_icon(
      Gdk::Pixbuf::create_from_resource(APP_PREFIX "icons/scalable/icon.svg"));

  set_position(Gtk::WindowPosition::WIN_POS_CENTER_ALWAYS);
}

Window::~Window() {}

Window* Window::create() {
  auto builder = Gtk::Builder::create_from_resource(APP_PREFIX "ui.glade");
  Window* window = nullptr;
  builder->get_widget_derived("main_window", window);
  return window;
}

void Window::on_finish_btn_clicked() {
  system("xterm -e \"pkexec update-grub\"");
  this->get_application()->quit();
}
