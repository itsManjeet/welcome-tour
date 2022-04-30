#include "config.h"
#include "interface/application.hh"
#include "style.hh"

int main(int argc, char** argv) {
#ifdef DEBUG
  Glib::setenv("GSETTINGS_SCHEMA_DIR", DATA_DIR, true);
#endif

  auto app = Application::create();
  auto provider = Gtk::CssProvider::create();
  if (!provider->load_from_data(STYLE_DATA)) {
    return 1;
  }

  auto screen = Gdk::Screen::get_default();
  auto ctxt = Gtk::StyleContext::create();

  ctxt->add_provider_for_screen(screen, provider,
                                GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

  return app->run(argc, argv);
}