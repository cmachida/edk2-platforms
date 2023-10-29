/** @file
  This driver produces the ACPI enable and disable SMI handlers.

Copyright (c) 2023, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _BMC_ACPI_SW_CHILD_H_
#define _BMC_ACPI_SW_CHILD_H_

//
// Statements that include other files
//
#include <Uefi.h>
#include <Library/BaseLib.h>
#include <Library/SmmLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/SmmServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>

#include "ServerManagement.h"

#include <Library/ServerMgmtRtLib.h>
#include <Protocol/IpmiTransportProtocol.h>
#include <Protocol/BmcAcpiSwChildPolicy.h>
#include <IndustryStandard/Ipmi.h>
#include <Library/IpmiBaseLib.h>

//
// Module prototypes
//

/**
  This is the standard EFI driver entrypoint. This function initializes
  the BMC ACPI SW Child protocol.

  @param ImageHandle - ImageHandle of the loaded driver
  @param SystemTable - Pointer to the System Table

  @retval EFI_SUCCESS - If all services discovered.
  @retval Other       - Failure in constructor.

**/
EFI_STATUS
EFIAPI
InitializeBmcAcpiSwChild (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

/**
  Send the time to the BMC, in the UNIX 32 bit format.

  @retval Status          - result of sending the time stamp

**/
EFI_STATUS
SyncTimeStamp (
  VOID
  );

/**
  Send a command to BMC to set the present power state.

  @param This
  @param PowerState
  @param DeviceState

  @retval EFI_SUCCESS               if successful
  @retval Other than EFI_SUCCESS    if not successful

**/
EFI_STATUS
SetACPIPowerStateInBMC (
  IN EFI_BMC_ACPI_SW_CHILD_POLICY_PROTOCOL  *This,
  IN UINT8                                  PowerState,
  IN UINT8                                  DeviceState
  );

#endif
