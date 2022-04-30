#ifndef WINDOW_HH
#define WINDOW_HH

#include <gtkmm.h>
#include <handy.h>

class Window : public Gtk::ApplicationWindow {
 private:
  Glib::RefPtr<Gtk::Builder> m_Builder;
  Glib::RefPtr<Gio::Settings> m_Settings;
  Gtk::HeaderBar* m_HeaderBar;
  Gtk::Button* m_FinishBtn;

 public:
  Window(BaseObjectType* cobject, Glib::RefPtr<Gtk::Builder> const& builder);
  ~Window();

  void on_finish_btn_clicked();

  static Window* create();
};

#endif