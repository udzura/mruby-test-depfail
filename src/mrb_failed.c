/*
** mrb_failed.c - Failed class
**
** Copyright (c) Uchio Kondo 2016
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_failed.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  int len;
} mrb_failed_data;

static const struct mrb_data_type mrb_failed_data_type = {
  "mrb_failed_data", mrb_free,
};

static mrb_value mrb_failed_init(mrb_state *mrb, mrb_value self)
{
  mrb_failed_data *data;
  char *str;
  int len;

  data = (mrb_failed_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_failed_data_type;
  DATA_PTR(self) = NULL;

  mrb_get_args(mrb, "s", &str, &len);
  data = (mrb_failed_data *)mrb_malloc(mrb, sizeof(mrb_failed_data));
  data->str = str;
  data->len = len;
  DATA_PTR(self) = data;

  return self;
}

static mrb_value mrb_failed_hello(mrb_state *mrb, mrb_value self)
{
  mrb_failed_data *data = DATA_PTR(self);

  return mrb_str_new(mrb, data->str, data->len);
}

static mrb_value mrb_failed_hi(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, "hi!!");
}

void mrb_mruby_test_depfail_gem_init(mrb_state *mrb)
{
    struct RClass *failed;
    failed = mrb_define_class(mrb, "Failed", mrb->object_class);
    mrb_define_method(mrb, failed, "initialize", mrb_failed_init, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, failed, "hello", mrb_failed_hello, MRB_ARGS_NONE());
    mrb_define_class_method(mrb, failed, "hi", mrb_failed_hi, MRB_ARGS_NONE());
    DONE;
}

void mrb_mruby_test_depfail_gem_final(mrb_state *mrb)
{
}

