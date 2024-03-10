#include <gtk/gtk.h>

void end_program(GtkWidget *wid, gpointer ptr)
{
  gtk_main_quit();
}

void combo_change(GtkWidget *wid, gpointer ptr)
{
  int sel = gtk_combo_box_get_active(GTK_COMBO_BOX(wid));
  char *selected = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(wid));

  printf("The value of the combo is %d %s.\n", sel, selected);
}

void main(int argc, char *argv[])
{
  gtk_init(&argc, &argv);

  int pos = 0;

  GtkWidget *grd = gtk_grid_new();
  GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  GtkWidget *btn = gtk_button_new_with_label("Close window");

  // combobox
  // GtkWidget *comb = gtk_combo_box_text_new();

  // gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(comb), "Option 1");
  // gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(comb), "Option 2");
  // gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(comb), "Option 3");
  // gtk_combo_box_set_active(GTK_COMBO_BOX(comb), 0);

  // list store
  GtkListStore *ls = gtk_list_store_new(1, G_TYPE_STRING);

  gtk_list_store_insert_with_values(ls, NULL, pos++, 0, "Option 1", -1);
  gtk_list_store_insert_with_values(ls, NULL, pos++, 0, "Option 2", -1);
  gtk_list_store_insert_with_values(ls, NULL, pos++, 0, "Option 3", -1);

  GtkTreeModelSort *sorted = GTK_TREE_MODEL_SORT(gtk_tree_model_sort_new_with_model(GTK_TREE_MODEL(ls)));
  GtkWidget *comb = gtk_combo_box_new_with_model(GTK_TREE_MODEL(sorted));
  GtkCellRenderer *rend = gtk_cell_renderer_text_new();

  gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(comb), rend, FALSE);
  gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(comb), rend, "text", 0);
  gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(sorted), 0, GTK_SORT_ASCENDING);

  // event handlers
  g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
  g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);
  g_signal_connect(comb, "changed", G_CALLBACK(combo_change), NULL);

  // grid layout
  gtk_grid_attach(GTK_GRID(grd), btn, 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grd), comb, 1, 0, 1, 1);
  gtk_container_add(GTK_CONTAINER(win), grd);
  gtk_widget_show_all(win);
  gtk_main();
}

