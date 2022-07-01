// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from unit_8_services_custom_msgs:srv/MyCustomServiceMessage.idl
// generated code does not contain a copyright notice
#include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__init(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request * msg)
{
  if (!msg) {
    return false;
  }
  // radius
  // repetitions
  return true;
}

void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__fini(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request * msg)
{
  if (!msg) {
    return;
  }
  // radius
  // repetitions
}

unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request *
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__create()
{
  unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request * msg = (unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request *)malloc(sizeof(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request));
  bool success = unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__destroy(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request * msg)
{
  if (msg) {
    unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__fini(msg);
  }
  free(msg);
}


bool
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence__init(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request * data = NULL;
  if (size) {
    data = (unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request *)calloc(size, sizeof(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence__fini(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence *
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence__create(size_t size)
{
  unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence * array = (unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence *)malloc(sizeof(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence__destroy(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence * array)
{
  if (array) {
    unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence__fini(array);
  }
  free(array);
}


bool
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__init(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__fini(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response *
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__create()
{
  unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response * msg = (unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response *)malloc(sizeof(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response));
  bool success = unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__destroy(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response * msg)
{
  if (msg) {
    unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__fini(msg);
  }
  free(msg);
}


bool
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence__init(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response * data = NULL;
  if (size) {
    data = (unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response *)calloc(size, sizeof(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence__fini(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence *
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence__create(size_t size)
{
  unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence * array = (unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence *)malloc(sizeof(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence__destroy(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence * array)
{
  if (array) {
    unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence__fini(array);
  }
  free(array);
}
