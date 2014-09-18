#include <pebble.h>

Window *window;
InverterLayer *inverter_layer;

TextLayer *time1_text_layer;
char time1_buffer[] = "      ";
TextLayer *time2_text_layer;
char time2_buffer[] = "        ";
TextLayer *time3_text_layer;
char time3_buffer[] = "     ";
TextLayer *date_text_layer;
char date_buffer[] = "          ";

void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  int hour = tick_time->tm_hour;
  switch (hour % 12) {
    case 0:
      strcpy(time1_buffer, "twelve");
      break;
    case 1:
      strcpy(time1_buffer, "one");
      break;
    case 2:
      strcpy(time1_buffer, "two");
      break;
    case 3:
      strcpy(time1_buffer, "three");
      break;
    case 4:
      strcpy(time1_buffer, "four");
      break;
    case 5:
      strcpy(time1_buffer, "five");
      break;
    case 6:
      strcpy(time1_buffer, "six");
      break;
    case 7:
      strcpy(time1_buffer, "seven");
      break;
    case 8:
      strcpy(time1_buffer, "eight");
      break;
    case 9:
      strcpy(time1_buffer, "nine");
      break;
    case 10:
      strcpy(time1_buffer, "ten");
      break;
    case 11:
      strcpy(time1_buffer, "eleven");
      break;
  }
  text_layer_set_text(time1_text_layer, time1_buffer);
  
  int min = tick_time->tm_min;
  int ten = min / 10;
  int one = min % 10;
  if (ten == 0) {
    switch (one) {
      case 0:
        strcpy(time2_buffer, "o'clock");
        break;
      case 1:
        strcpy(time2_buffer, "o'one");
        break;
      case 2:
        strcpy(time2_buffer, "o'two");
        break;
      case 3:
        strcpy(time2_buffer, "o'three");
        break;
      case 4:
        strcpy(time2_buffer, "o'four");
        break;
      case 5:
        strcpy(time2_buffer, "o'five");
        break;
      case 6:
        strcpy(time2_buffer, "o'six");
        break;
      case 7:
        strcpy(time2_buffer, "o'seven");
        break;
      case 8:
        strcpy(time2_buffer, "o'eight");
        break;
      case 9:
        strcpy(time2_buffer, "o'nine");
        break;
    }
    strcpy(time3_buffer, "");
  } else if (ten == 1) {
    switch (one) {
      case 0:
        strcpy(time2_buffer, "ten");
        strcpy(time3_buffer, "");
        break;
      case 1:
        strcpy(time2_buffer, "eleven");
        strcpy(time3_buffer, "");
        break;
      case 2:
        strcpy(time2_buffer, "twelve");
        strcpy(time3_buffer, "");
        break;
      case 3:
        strcpy(time2_buffer, "thirteen");
        strcpy(time3_buffer, "");
        break;
      case 4:
        strcpy(time2_buffer, "fourteen");
        strcpy(time3_buffer, "");
        break;
      case 5:
        strcpy(time2_buffer, "fifteen");
        strcpy(time3_buffer, "");
        break;
      case 6:
        strcpy(time2_buffer, "sixteen");
        strcpy(time3_buffer, "");
        break;
      case 7:
        strcpy(time2_buffer, "seven");
        strcpy(time3_buffer, "teen");
        break;
      case 8:
        strcpy(time2_buffer, "eight");
        strcpy(time3_buffer, "teen");
        break;
      case 9:
        strcpy(time2_buffer, "nine");
        strcpy(time3_buffer, "teen");
        break;
    }
  } else {
    switch (ten) {
      case 2:
        strcpy(time2_buffer, "twenty");
        break;
      case 3:
        strcpy(time2_buffer, "thirty");
        break;
      case 4:
        strcpy(time2_buffer, "forty");
        break;
      case 5:
        strcpy(time2_buffer, "fifty");
        break;
    }
    switch (one) {
      case 0:
        strcpy(time3_buffer, "");
        break;
      case 1:
        strcpy(time3_buffer, "one");
        break;
      case 2:
        strcpy(time3_buffer, "two");
        break;
      case 3:
        strcpy(time3_buffer, "three");
        break;
      case 4:
        strcpy(time3_buffer, "four");
        break;
      case 5:
        strcpy(time3_buffer, "five");
        break;
      case 6:
        strcpy(time3_buffer, "six");
        break;
      case 7:
        strcpy(time3_buffer, "seven");
        break;
      case 8:
        strcpy(time3_buffer, "eight");
        break;
      case 9:
        strcpy(time3_buffer, "nine");
        break;
    }
  }
  text_layer_set_text(time2_text_layer, time2_buffer);
  text_layer_set_text(time3_text_layer, time3_buffer);
  
  if (units_changed & DAY_UNIT) {
    char wday_buffer[4];
    int wday = tick_time->tm_wday;
    switch (wday) {
      case 0:
        strcpy(wday_buffer, "sun");
        break;
      case 1:
        strcpy(wday_buffer, "mon");
        break;
      case 2:
        strcpy(wday_buffer, "tue");
        break;
      case 3:
        strcpy(wday_buffer, "wed");
        break;
      case 4:
        strcpy(wday_buffer, "thu");
        break;
      case 5:
        strcpy(wday_buffer, "fri");
        break;
      case 6:
        strcpy(wday_buffer, "sat");
        break;
    }
    
    int mday = tick_time->tm_mday;
    
    char mon_buffer[10];
    int mon = tick_time->tm_mon;
    switch (mon) {
      case 0:
        strcpy(mon_buffer, "jan");
        break;
      case 1:
        strcpy(mon_buffer, "feb");
        break;
      case 2:
        strcpy(mon_buffer, "mar");
        break;
      case 3:
        strcpy(mon_buffer, "apr");
        break;
      case 4:
        strcpy(mon_buffer, "may");
        break;
      case 5:
        strcpy(mon_buffer, "jun");
        break;
      case 6:
        strcpy(mon_buffer, "jul");
        break;
      case 7:
        strcpy(mon_buffer, "aug");
        break;
      case 8:
        strcpy(mon_buffer, "sep");
        break;
      case 9:
        strcpy(mon_buffer, "oct");
        break;
      case 10:
        strcpy(mon_buffer, "nov");
        break;
      case 11:
        strcpy(mon_buffer, "dec");
        break;
    }
    
    snprintf(date_buffer, sizeof date_buffer, "%s %i %s", wday_buffer, mday, mon_buffer);
  }
}

void window_load(Window *window) {
  time1_text_layer = text_layer_create(GRect(2, 10, 142, 64));
  text_layer_set_background_color(time1_text_layer, GColorClear);
  text_layer_set_text_color(time1_text_layer, GColorBlack);
  text_layer_set_font(time1_text_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_HELVETICA_BOLD_38)));
  text_layer_set_text(time1_text_layer, time1_buffer);
  layer_add_child(window_get_root_layer(window), (Layer*) time1_text_layer);
  
  time2_text_layer = text_layer_create(GRect(2, 48, 142, 64));
  text_layer_set_background_color(time2_text_layer, GColorClear);
  text_layer_set_text_color(time2_text_layer, GColorBlack);
  text_layer_set_font(time2_text_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_HELVETICA_LIGHT_38)));
  text_layer_set_text(time2_text_layer, time2_buffer);
  layer_add_child(window_get_root_layer(window), (Layer*) time2_text_layer);
  
  time3_text_layer = text_layer_create(GRect(2, 84, 142, 64));
  text_layer_set_background_color(time3_text_layer, GColorClear);
  text_layer_set_text_color(time3_text_layer, GColorBlack);
  text_layer_set_font(time3_text_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_HELVETICA_LIGHT_38)));
  text_layer_set_text(time3_text_layer, time3_buffer);
  layer_add_child(window_get_root_layer(window), (Layer*) time3_text_layer);
  
  date_text_layer = text_layer_create(GRect(0, 139, 142, 30));
  text_layer_set_background_color(date_text_layer, GColorClear);
  text_layer_set_text_color(date_text_layer, GColorBlack);
  text_layer_set_text_alignment(date_text_layer, GTextAlignmentRight);
  text_layer_set_font(date_text_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_HELVETICA_22)));
  text_layer_set_text(date_text_layer, date_buffer);
  layer_add_child(window_get_root_layer(window), (Layer*) date_text_layer);
  
  inverter_layer = inverter_layer_create(GRect(0, 0, 144, 168));
  layer_add_child(window_get_root_layer(window), (Layer*) inverter_layer);
  
  time_t temp = time(NULL);
  tick_handler(localtime(&temp), DAY_UNIT);
}

void window_unload(Window *window) {
}

void init() {
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  
  window_stack_push(window, true);
  
  tick_timer_service_subscribe(MINUTE_UNIT, (TickHandler) tick_handler);
}

void deinit() {
  tick_timer_service_unsubscribe();
  
  text_layer_destroy(time1_text_layer);
  text_layer_destroy(time2_text_layer);
  text_layer_destroy(time3_text_layer);
  text_layer_destroy(date_text_layer);
  
  inverter_layer_destroy(inverter_layer);
  
  window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
