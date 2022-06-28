#include <filesystem>
#include <fstream>
#include <iostream>

#include "config.h"
#include "interface/application.hh"
#include "style.hh"

int main(int argc, char** argv) {
#ifdef DEBUG
  Glib::setenv("GSETTINGS_SCHEMA_DIR", DATA_DIR, true);
#endif

  std::filesystem::path config_path = std::getenv("HOME");
  config_path = config_path / ".config" / "welcome-tour-done";
  if (std::filesystem::exists(config_path)) {
    return 0;
  }

  if (!std::filesystem::exists(config_path.parent_path())) {
    std::error_code error;
    std::filesystem::create_directories(config_path.parent_path(), error);
    if (error) {
      std::cerr << "ERROR: Failed to create " << config_path.parent_path()
                << ", " << error.message() << std::endl;
    }
  }

  {
    std::ofstream file(config_path);
    file << "done";
    file.close();
  }

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