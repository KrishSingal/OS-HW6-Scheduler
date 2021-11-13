// SPDX-License-Identifier: GPL-2.0
// Trace events for the ChromeOS Embedded Controller
//
// Copyright 2019 Google LLC.

#define TRACE_SYMBOL(a) {a, #a}

// Generate the list using the following script:
// sed -n 's/^#define \(EC_CMD_[[:alnum:]_]*\)\s.*/\tTRACE_SYMBOL(\1), \\/p' include/linux/platform_data/cros_ec_commands.h
#define EC_CMDS \
	TRACE_SYMBOL(EC_CMD_ACPI_READ), \
	TRACE_SYMBOL(EC_CMD_ACPI_WRITE), \
	TRACE_SYMBOL(EC_CMD_ACPI_BURST_ENABLE), \
	TRACE_SYMBOL(EC_CMD_ACPI_BURST_DISABLE), \
	TRACE_SYMBOL(EC_CMD_ACPI_QUERY_EVENT), \
	TRACE_SYMBOL(EC_CMD_PROTO_VERSION), \
	TRACE_SYMBOL(EC_CMD_HELLO), \
	TRACE_SYMBOL(EC_CMD_GET_VERSION), \
	TRACE_SYMBOL(EC_CMD_READ_TEST), \
	TRACE_SYMBOL(EC_CMD_GET_BUILD_INFO), \
	TRACE_SYMBOL(EC_CMD_GET_CHIP_INFO), \
	TRACE_SYMBOL(EC_CMD_GET_BOARD_VERSION), \
	TRACE_SYMBOL(EC_CMD_READ_MEMMAP), \
	TRACE_SYMBOL(EC_CMD_GET_CMD_VERSIONS), \
	TRACE_SYMBOL(EC_CMD_GET_COMMS_STATUS), \
	TRACE_SYMBOL(EC_CMD_TEST_PROTOCOL), \
	TRACE_SYMBOL(EC_CMD_GET_PROTOCOL_INFO), \
	TRACE_SYMBOL(EC_CMD_GSV_PAUSE_IN_S5), \
	TRACE_SYMBOL(EC_CMD_GET_FEATURES), \
	TRACE_SYMBOL(EC_CMD_GET_SKU_ID), \
	TRACE_SYMBOL(EC_CMD_SET_SKU_ID), \
	TRACE_SYMBOL(EC_CMD_FLASH_INFO), \
	TRACE_SYMBOL(EC_CMD_FLASH_READ), \
	TRACE_SYMBOL(EC_CMD_FLASH_WRITE), \
	TRACE_SYMBOL(EC_CMD_FLASH_ERASE), \
	TRACE_SYMBOL(EC_CMD_FLASH_PROTECT), \
	TRACE_SYMBOL(EC_CMD_FLASH_REGION_INFO), \
	TRACE_SYMBOL(EC_CMD_VBNV_CONTEXT), \
	TRACE_SYMBOL(EC_CMD_FLASH_SPI_INFO), \
	TRACE_SYMBOL(EC_CMD_FLASH_SELECT), \
	TRACE_SYMBOL(EC_CMD_PWM_GET_FAN_TARGET_RPM), \
	TRACE_SYMBOL(EC_CMD_PWM_SET_FAN_TARGET_RPM), \
	TRACE_SYMBOL(EC_CMD_PWM_GET_KEYBOARD_BACKLIGHT), \
	TRACE_SYMBOL(EC_CMD_PWM_SET_KEYBOARD_BACKLIGHT), \
	TRACE_SYMBOL(EC_CMD_PWM_SET_FAN_DUTY), \
	TRACE_SYMBOL(EC_CMD_PWM_SET_DUTY), \
	TRACE_SYMBOL(EC_CMD_PWM_GET_DUTY), \
	TRACE_SYMBOL(EC_CMD_LIGHTBAR_CMD), \
	TRACE_SYMBOL(EC_CMD_LED_CONTROL), \
	TRACE_SYMBOL(EC_CMD_VBOOT_HASH), \
	TRACE_SYMBOL(EC_CMD_MOTION_SENSE_CMD), \
	TRACE_SYMBOL(EC_CMD_FORCE_LID_OPEN), \
	TRACE_SYMBOL(EC_CMD_CONFIG_POWER_BUTTON), \
	TRACE_SYMBOL(EC_CMD_USB_CHARGE_SET_MODE), \
	TRACE_SYMBOL(EC_CMD_PSTORE_INFO), \
	TRACE_SYMBOL(EC_CMD_PSTORE_READ), \
	TRACE_SYMBOL(EC_CMD_PSTORE_WRITE), \
	TRACE_SYMBOL(EC_CMD_RTC_GET_VALUE), \
	TRACE_SYMBOL(EC_CMD_RTC_GET_ALARM), \
	TRACE_SYMBOL(EC_CMD_RTC_SET_VALUE), \
	TRACE_SYMBOL(EC_CMD_RTC_SET_ALARM), \
	TRACE_SYMBOL(EC_CMD_PORT80_LAST_BOOT), \
	TRACE_SYMBOL(EC_CMD_PORT80_READ), \
	TRACE_SYMBOL(EC_CMD_VSTORE_INFO), \
	TRACE_SYMBOL(EC_CMD_VSTORE_READ), \
	TRACE_SYMBOL(EC_CMD_VSTORE_WRITE), \
	TRACE_SYMBOL(EC_CMD_THERMAL_SET_THRESHOLD), \
	TRACE_SYMBOL(EC_CMD_THERMAL_GET_THRESHOLD), \
	TRACE_SYMBOL(EC_CMD_THERMAL_AUTO_FAN_CTRL), \
	TRACE_SYMBOL(EC_CMD_TMP006_GET_CALIBRATION), \
	TRACE_SYMBOL(EC_CMD_TMP006_SET_CALIBRATION), \
	TRACE_SYMBOL(EC_CMD_TMP006_GET_RAW), \
	TRACE_SYMBOL(EC_CMD_MKBP_STATE), \
	TRACE_SYMBOL(EC_CMD_MKBP_INFO), \
	TRACE_SYMBOL(EC_CMD_MKBP_SIMULATE_KEY), \
	TRACE_SYMBOL(EC_CMD_GET_KEYBOARD_ID), \
	TRACE_SYMBOL(EC_CMD_MKBP_SET_CONFIG), \
	TRACE_SYMBOL(EC_CMD_MKBP_GET_CONFIG), \
	TRACE_SYMBOL(EC_CMD_KEYSCAN_SEQ_CTRL), \
	TRACE_SYMBOL(EC_CMD_GET_NEXT_EVENT), \
	TRACE_SYMBOL(EC_CMD_KEYBOARD_FACTORY_TEST), \
	TRACE_SYMBOL(EC_CMD_TEMP_SENSOR_GET_INFO), \
	TRACE_SYMBOL(EC_CMD_HOST_EVENT_GET_B), \
	TRACE_SYMBOL(EC_CMD_HOST_EVENT_GET_SMI_MASK), \
	TRACE_SYMBOL(EC_CMD_HOST_EVENT_GET_SCI_MASK), \
	TRACE_SYMBOL(EC_CMD_HOST_EVENT_GET_WAKE_MASK), \
	TRACE_SYMBOL(EC_CMD_HOST_EVENT_SET_SMI_MASK), \
	TRACE_SYMBOL(EC_CMD_HOST_EVENT_SET_SCI_MASK), \
	TRACE_SYMBOL(EC_CMD_HOST_EVENT_CLEAR), \
	TRACE_SYMBOL(EC_CMD_HOST_EVENT_SET_WAKE_MASK), \
	TRACE_SYMBOL(EC_CMD_HOST_EVENT_CLEAR_B), \
	TRACE_SYMBOL(EC_CMD_HOST_EVENT), \
	TRACE_SYMBOL(EC_CMD_SWITCH_ENABLE_BKLIGHT), \
	TRACE_SYMBOL(EC_CMD_SWITCH_ENABLE_WIRELESS), \
	TRACE_SYMBOL(EC_CMD_GPIO_SET), \
	TRACE_SYMBOL(EC_CMD_GPIO_GET), \
	TRACE_SYMBOL(EC_CMD_I2C_READ), \
	TRACE_SYMBOL(EC_CMD_I2C_WRITE), \
	TRACE_SYMBOL(EC_CMD_CHARGE_CONTROL), \
	TRACE_SYMBOL(EC_CMD_CONSOLE_SNAPSHOT), \
	TRACE_SYMBOL(EC_CMD_CONSOLE_READ), \
	TRACE_SYMBOL(EC_CMD_BATTERY_CUT_OFF), \
	TRACE_SYMBOL(EC_CMD_USB_MUX), \
	TRACE_SYMBOL(EC_CMD_LDO_SET), \
	TRACE_SYMBOL(EC_CMD_LDO_GET), \
	TRACE_SYMBOL(EC_CMD_POWER_INFO), \
	TRACE_SYMBOL(EC_CMD_I2C_PASSTHRU), \
	TRACE_SYMBOL(EC_CMD_HANG_DETECT), \
	TRACE_SYMBOL(EC_CMD_CHARGE_STATE), \
	TRACE_SYMBOL(EC_CMD_CHARGE_CURRENT_LIMIT), \
	TRACE_SYMBOL(EC_CMD_EXTERNAL_POWER_LIMIT), \
	TRACE_SYMBOL(EC_CMD_OVERRIDE_DEDICATED_CHARGER_LIMIT), \
	TRACE_SYMBOL(EC_CMD_HIBERNATION_DELAY), \
	TRACE_SYMBOL(EC_CMD_HOST_SLEEP_EVENT), \
	TRACE_SYMBOL(EC_CMD_DEVICE_EVENT), \
	TRACE_SYMBOL(EC_CMD_SB_READ_WORD), \
	TRACE_SYMBOL(EC_CMD_SB_WRITE_WORD), \
	TRACE_SYMBOL(EC_CMD_SB_READ_BLOCK), \
	TRACE_SYMBOL(EC_CMD_SB_WRITE_BLOCK), \
	TRACE_SYMBOL(EC_CMD_BATTERY_VENDOR_PARAM), \
	TRACE_SYMBOL(EC_CMD_SB_FW_UPDATE), \
	TRACE_SYMBOL(EC_CMD_ENTERING_MODE), \
	TRACE_SYMBOL(EC_CMD_I2C_PASSTHRU_PROTECT), \
	TRACE_SYMBOL(EC_CMD_CEC_WRITE_MSG), \
	TRACE_SYMBOL(EC_CMD_CEC_SET), \
	TRACE_SYMBOL(EC_CMD_CEC_GET), \
	TRACE_SYMBOL(EC_CMD_EC_CODEC), \
	TRACE_SYMBOL(EC_CMD_EC_CODEC_DMIC), \
	TRACE_SYMBOL(EC_CMD_EC_CODEC_I2S_RX), \
	TRACE_SYMBOL(EC_CMD_EC_CODEC_WOV), \
	TRACE_SYMBOL(EC_CMD_REBOOT_EC), \
	TRACE_SYMBOL(EC_CMD_GET_PANIC_INFO), \
	TRACE_SYMBOL(EC_CMD_REBOOT), \
	TRACE_SYMBOL(EC_CMD_RESEND_RESPONSE), \
	TRACE_SYMBOL(EC_CMD_VERSION0), \
	TRACE_SYMBOL(EC_CMD_PD_EXCHANGE_STATUS), \
	TRACE_SYMBOL(EC_CMD_PD_HOST_EVENT_STATUS), \
	TRACE_SYMBOL(EC_CMD_USB_PD_CONTROL), \
	TRACE_SYMBOL(EC_CMD_USB_PD_PORTS), \
	TRACE_SYMBOL(EC_CMD_USB_PD_POWER_INFO), \
	TRACE_SYMBOL(EC_CMD_CHARGE_PORT_COUNT), \
	TRACE_SYMBOL(EC_CMD_USB_PD_FW_UPDATE), \
	TRACE_SYMBOL(EC_CMD_USB_PD_RW_HASH_ENTRY), \
	TRACE_SYMBOL(EC_CMD_USB_PD_DEV_INFO), \
	TRACE_SYMBOL(EC_CMD_USB_PD_DISCOVERY), \
	TRACE_SYMBOL(EC_CMD_PD_CHARGE_PORT_OVERRIDE), \
	TRACE_SYMBOL(EC_CMD_PD_GET_LOG_ENTRY), \
	TRACE_SYMBOL(EC_CMD_USB_PD_GET_AMODE), \
	TRACE_SYMBOL(EC_CMD_USB_PD_SET_AMODE), \
	TRACE_SYMBOL(EC_CMD_PD_WRITE_LOG_ENTRY), \
	TRACE_SYMBOL(EC_CMD_PD_CONTROL), \
	TRACE_SYMBOL(EC_CMD_USB_PD_MUX_INFO), \
	TRACE_SYMBOL(EC_CMD_PD_CHIP_INFO), \
	TRACE_SYMBOL(EC_CMD_RWSIG_CHECK_STATUS), \
	TRACE_SYMBOL(EC_CMD_RWSIG_ACTION), \
	TRACE_SYMBOL(EC_CMD_EFS_VERIFY), \
	TRACE_SYMBOL(EC_CMD_GET_CROS_BOARD_INFO), \
	TRACE_SYMBOL(EC_CMD_SET_CROS_BOARD_INFO), \
	TRACE_SYMBOL(EC_CMD_GET_UPTIME_INFO), \
	TRACE_SYMBOL(EC_CMD_ADD_ENTROPY), \
	TRACE_SYMBOL(EC_CMD_ADC_READ), \
	TRACE_SYMBOL(EC_CMD_ROLLBACK_INFO), \
	TRACE_SYMBOL(EC_CMD_AP_RESET), \
	TRACE_SYMBOL(EC_CMD_REGULATOR_GET_INFO), \
	TRACE_SYMBOL(EC_CMD_REGULATOR_ENABLE), \
	TRACE_SYMBOL(EC_CMD_REGULATOR_IS_ENABLED), \
	TRACE_SYMBOL(EC_CMD_REGULATOR_SET_VOLTAGE), \
	TRACE_SYMBOL(EC_CMD_REGULATOR_GET_VOLTAGE), \
	TRACE_SYMBOL(EC_CMD_CR51_BASE), \
	TRACE_SYMBOL(EC_CMD_CR51_LAST), \
	TRACE_SYMBOL(EC_CMD_FP_PASSTHRU), \
	TRACE_SYMBOL(EC_CMD_FP_MODE), \
	TRACE_SYMBOL(EC_CMD_FP_INFO), \
	TRACE_SYMBOL(EC_CMD_FP_FRAME), \
	TRACE_SYMBOL(EC_CMD_FP_TEMPLATE), \
	TRACE_SYMBOL(EC_CMD_FP_CONTEXT), \
	TRACE_SYMBOL(EC_CMD_FP_STATS), \
	TRACE_SYMBOL(EC_CMD_FP_SEED), \
	TRACE_SYMBOL(EC_CMD_FP_ENC_STATUS), \
	TRACE_SYMBOL(EC_CMD_TP_SELF_TEST), \
	TRACE_SYMBOL(EC_CMD_TP_FRAME_INFO), \
	TRACE_SYMBOL(EC_CMD_TP_FRAME_SNAPSHOT), \
	TRACE_SYMBOL(EC_CMD_TP_FRAME_GET), \
	TRACE_SYMBOL(EC_CMD_BATTERY_GET_STATIC), \
	TRACE_SYMBOL(EC_CMD_BATTERY_GET_DYNAMIC), \
	TRACE_SYMBOL(EC_CMD_CHARGER_CONTROL), \
	TRACE_SYMBOL(EC_CMD_BOARD_SPECIFIC_BASE), \
	TRACE_SYMBOL(EC_CMD_BOARD_SPECIFIC_LAST)

/* See the enum ec_status in include/linux/platform_data/cros_ec_commands.h */
#define EC_RESULT \
	TRACE_SYMBOL(EC_RES_SUCCESS), \
	TRACE_SYMBOL(EC_RES_INVALID_COMMAND), \
	TRACE_SYMBOL(EC_RES_ERROR), \
	TRACE_SYMBOL(EC_RES_INVALID_PARAM), \
	TRACE_SYMBOL(EC_RES_ACCESS_DENIED), \
	TRACE_SYMBOL(EC_RES_INVALID_RESPONSE), \
	TRACE_SYMBOL(EC_RES_INVALID_VERSION), \
	TRACE_SYMBOL(EC_RES_INVALID_CHECKSUM), \
	TRACE_SYMBOL(EC_RES_IN_PROGRESS), \
	TRACE_SYMBOL(EC_RES_UNAVAILABLE), \
	TRACE_SYMBOL(EC_RES_TIMEOUT), \
	TRACE_SYMBOL(EC_RES_OVERFLOW), \
	TRACE_SYMBOL(EC_RES_INVALID_HEADER), \
	TRACE_SYMBOL(EC_RES_REQUEST_TRUNCATED), \
	TRACE_SYMBOL(EC_RES_RESPONSE_TOO_BIG), \
	TRACE_SYMBOL(EC_RES_BUS_ERROR), \
	TRACE_SYMBOL(EC_RES_BUSY), \
	TRACE_SYMBOL(EC_RES_INVALID_HEADER_VERSION), \
	TRACE_SYMBOL(EC_RES_INVALID_HEADER_CRC), \
	TRACE_SYMBOL(EC_RES_INVALID_DATA_CRC), \
	TRACE_SYMBOL(EC_RES_DUP_UNAVAILABLE)

#define CREATE_TRACE_POINTS
#include "cros_ec_trace.h"