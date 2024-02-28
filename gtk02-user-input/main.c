#include <gtk/gtk.h>

GtkWidget *txt;

void check_toggle(GtkWidget *wid, gpointer ptr)
{
  printf("The state of the button is %d\n", gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wid)));
}

void end_program(GtkWidget *wid, gpointer ptr)
{
  gtk_main_quit();
}

void copy_text(GtkWidget *wid, gpointer ptr)
{
  const char *input = gtk_entry_get_text(GTK_ENTRY(txt));

  gtk_label_set_text(GTK_LABEL(ptr), input);
}

void main(int argc, char *argv[])
{
  gtk_init(&argc, &argv);

  GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  GtkWidget *btn = gtk_button_new_with_label("Close window");
  GtkWidget *lbl = gtk_label_new("My label");
  GtkWidget *btn2 = gtk_button_new_with_label("Copy button");
  GtkWidget *chk = gtk_check_button_new_with_label("Check");

  GtkAdjustment *adj = gtk_adjustment_new(0, -10, 10, 1, 0, 0);

  GtkWidget *rad1 = gtk_radio_button_new_with_label(NULL, "Button 1");
  GSList *group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(rad1));
  GtkWidget *rad2 = gtk_radio_button_new_with_label(group, "Button 2");

  GtkWidget *grd = gtk_grid_new();

  int state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chk));

  g_signal_connect(chk, "toggled", G_CALLBACK(check_toggle), NULL);
  g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
  g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);
  g_signal_connect(btn2, "clicked", G_CALLBACK(copy_text), lbl);

  // txt = gtk_entry_new();
  txt = gtk_spin_button_new(adj, 0, 0);

  gtk_grid_attach(GTK_GRID(grd), lbl, 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grd), btn2, 1, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grd), btn, 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grd), txt, 1, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grd), chk, 0, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grd), rad1, 0, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grd), rad2, 1, 3, 1, 1);
  gtk_container_add(GTK_CONTAINER(win), grd);
  gtk_widget_show_all(win);
  gtk_main();
}