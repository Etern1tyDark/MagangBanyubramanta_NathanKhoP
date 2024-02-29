# generated from rosidl_generator_py/resource/_idl.py.em
# with input from flare_detect:msg/Detected.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Detected(type):
    """Metaclass of message 'Detected'."""

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
            module = import_type_support('flare_detect')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'flare_detect.msg.Detected')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__detected
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__detected
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__detected
            cls._TYPE_SUPPORT = module.type_support_msg__msg__detected
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__detected

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Detected(metaclass=Metaclass_Detected):
    """Message class 'Detected'."""

    __slots__ = [
        '_red',
        '_yellow',
        '_blue',
    ]

    _fields_and_field_types = {
        'red': 'int32',
        'yellow': 'int32',
        'blue': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.red = kwargs.get('red', int())
        self.yellow = kwargs.get('yellow', int())
        self.blue = kwargs.get('blue', int())

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
        if self.red != other.red:
            return False
        if self.yellow != other.yellow:
            return False
        if self.blue != other.blue:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def red(self):
        """Message field 'red'."""
        return self._red

    @red.setter
    def red(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'red' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'red' field must be an integer in [-2147483648, 2147483647]"
        self._red = value

    @builtins.property
    def yellow(self):
        """Message field 'yellow'."""
        return self._yellow

    @yellow.setter
    def yellow(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'yellow' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'yellow' field must be an integer in [-2147483648, 2147483647]"
        self._yellow = value

    @builtins.property
    def blue(self):
        """Message field 'blue'."""
        return self._blue

    @blue.setter
    def blue(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'blue' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'blue' field must be an integer in [-2147483648, 2147483647]"
        self._blue = value
