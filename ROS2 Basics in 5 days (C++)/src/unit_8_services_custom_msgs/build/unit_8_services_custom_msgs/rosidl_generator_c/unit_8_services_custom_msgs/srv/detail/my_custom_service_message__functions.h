// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from unit_8_services_custom_msgs:srv/MyCustomServiceMessage.idl
// generated code does not contain a copyright notice

#ifndef UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__FUNCTIONS_H_
#define UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "unit_8_services_custom_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__struct.h"

/// Initialize srv/MyCustomServiceMessage message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request
 * )) before or use
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
bool
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__init(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request * msg);

/// Finalize srv/MyCustomServiceMessage message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__fini(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request * msg);

/// Create srv/MyCustomServiceMessage message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request *
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__create();

/// Destroy srv/MyCustomServiceMessage message.
/**
 * It calls
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__destroy(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request * msg);


/// Initialize array of srv/MyCustomServiceMessage messages.
/**
 * It allocates the memory for the number of elements and calls
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
bool
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence__init(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence * array, size_t size);

/// Finalize array of srv/MyCustomServiceMessage messages.
/**
 * It calls
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence__fini(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence * array);

/// Create array of srv/MyCustomServiceMessage messages.
/**
 * It allocates the memory for the array and calls
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence *
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence__create(size_t size);

/// Destroy array of srv/MyCustomServiceMessage messages.
/**
 * It calls
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence__destroy(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence * array);

/// Initialize srv/MyCustomServiceMessage message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response
 * )) before or use
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
bool
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__init(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response * msg);

/// Finalize srv/MyCustomServiceMessage message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__fini(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response * msg);

/// Create srv/MyCustomServiceMessage message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response *
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__create();

/// Destroy srv/MyCustomServiceMessage message.
/**
 * It calls
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__destroy(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response * msg);


/// Initialize array of srv/MyCustomServiceMessage messages.
/**
 * It allocates the memory for the number of elements and calls
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
bool
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence__init(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence * array, size_t size);

/// Finalize array of srv/MyCustomServiceMessage messages.
/**
 * It calls
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence__fini(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence * array);

/// Create array of srv/MyCustomServiceMessage messages.
/**
 * It allocates the memory for the array and calls
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence *
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence__create(size_t size);

/// Destroy array of srv/MyCustomServiceMessage messages.
/**
 * It calls
 * unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_unit_8_services_custom_msgs
void
unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence__destroy(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__FUNCTIONS_H_
