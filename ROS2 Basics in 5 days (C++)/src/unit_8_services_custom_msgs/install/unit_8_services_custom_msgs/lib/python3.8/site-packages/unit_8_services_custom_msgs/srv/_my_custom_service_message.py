# generated from rosidl_generator_py/resource/_idl.py.em
# with input from unit_8_services_custom_msgs:srv/MyCustomServiceMessage.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MyCustomServiceMessage_Request(type):
    """Metaclass of message 'MyCustomServiceMessage_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('unit_8_services_custom_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'unit_8_services_custom_msgs.srv.MyCustomServiceMessage_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__my_custom_service_message__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__my_custom_service_message__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__my_custom_service_message__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__my_custom_service_message__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__my_custom_service_message__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MyCustomServiceMessage_Request(metaclass=Metaclass_MyCustomServiceMessage_Request):
    """Message class 'MyCustomServiceMessage_Request'."""

    __slots__ = [
        '_radius',
        '_repetitions',
    ]

    _fields_and_field_types = {
        'radius': 'double',
        'repetitions': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.radius = kwargs.get('radius', float())
        self.repetitions = kwargs.get('repetitions', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.radius != other.radius:
            return False
        if self.repetitions != other.repetitions:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def radius(self):
        """Message field 'radius'."""
        return self._radius

    @radius.setter
    def radius(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'radius' field must be of type 'float'"
        self._radius = value

    @property
    def repetitions(self):
        """Message field 'repetitions'."""
        return self._repetitions

    @repetitions.setter
    def repetitions(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'repetitions' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'repetitions' field must be an integer in [-2147483648, 2147483647]"
        self._repetitions = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_MyCustomServiceMessage_Response(type):
    """Metaclass of message 'MyCustomServiceMessage_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('unit_8_services_custom_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'unit_8_services_custom_msgs.srv.MyCustomServiceMessage_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__my_custom_service_message__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__my_custom_service_message__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__my_custom_service_message__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__my_custom_service_message__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__my_custom_service_message__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MyCustomServiceMessage_Response(metaclass=Metaclass_MyCustomServiceMessage_Response):
    """Message class 'MyCustomServiceMessage_Response'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_MyCustomServiceMessage(type):
    """Metaclass of service 'MyCustomServiceMessage'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('unit_8_services_custom_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'unit_8_services_custom_msgs.srv.MyCustomServiceMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__my_custom_service_message

            from unit_8_services_custom_msgs.srv import _my_custom_service_message
            if _my_custom_service_message.Metaclass_MyCustomServiceMessage_Request._TYPE_SUPPORT is None:
                _my_custom_service_message.Metaclass_MyCustomServiceMessage_Request.__import_type_support__()
            if _my_custom_service_message.Metaclass_MyCustomServiceMessage_Response._TYPE_SUPPORT is None:
                _my_custom_service_message.Metaclass_MyCustomServiceMessage_Response.__import_type_support__()


class MyCustomServiceMessage(metaclass=Metaclass_MyCustomServiceMessage):
    from unit_8_services_custom_msgs.srv._my_custom_service_message import MyCustomServiceMessage_Request as Request
    from unit_8_services_custom_msgs.srv._my_custom_service_message import MyCustomServiceMessage_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
