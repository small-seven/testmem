#include <fsl-mc/fsl_mc_sys.h>
#include <fsl-mc/fsl_mc_cmd.h>
#include <fsl-mc/fsl_dpni.h>
int dpni_destroy(struct fsl_mc_io *mc_io,
		 uint16_t dprc_token,
		 uint32_t cmd_flags,
		 uint32_t obj_id)
{
	struct mc_command cmd = { 0 };

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_DESTROY,
					  cmd_flags,
					  dprc_token);

	/* set object id to destroy */
	CMD_DESTROY_SET_OBJ_ID_PARAM0(cmd, obj_id);

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}
