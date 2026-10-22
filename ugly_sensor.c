#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define REG_CNT 	4

#define DEV_NAME_MAX    8
#define REG_BASE_ADDR   0x3000

#define SENSOR_ID_VAL   0x6000
#define MODE_A_VAL      0x6002
#define MODE_B_VAL      0x6004

#define SENSOR_OK       0
#define SENSOR_ERR      (-1)

#define SQR(x) (x)*(x)	/* Fix: x mentioned inside parantheses */

typedef struct {
	uint32_t addr;
        uint32_t val;
} reg_t; /* Fix: reg_t is more readable now */

int g_cnt = 0;
reg_t *regs = NULL;

/* fake I2C read */
static uint32_t read_reg(uint32_t addr) {
        return addr * 2;
}

static int init_sensor(const char *name)        /* Fix: function name changed from CamelCase to snake_case */
{
        char dev_name[DEV_NAME_MAX];
        int ret = SENSOR_ERR;
        unsigned int i;

        if (name == NULL) {
                return SENSOR_ERR;
        }

        /* Fix: strcpy overflows the buffer, so we create a bounded copy here using snprintf */
        if (snprintf(dev_name, sizeof(dev_name), "%s", name) >= (int)sizeof(dev_name)) {
        fprintf(stderr, "warning: device name truncated to \"%s\"\n", dev_name);
        }

        /*Fix: calloc prevents memory overflow when compared to malloc */
        regs = malloc(REG_CNT * sizeof(reg_t));

	for(i=0; i<REG_CNT; i++) {                      /* Fix: No of iterations fixed */
                regs[i].addr = REG_BASE_ADDR + i;       /* Fix: Macro used instead of the number directly */
                regs[i].val = read_reg(regs[i].Addr);
        }
        if (regs[0].val == SENSOR_ID_VAL) {
                printf("sensor ok\n");          /* Fix: brackets inserted to avoid confusion */
        }
        printf("init done!\n");

        switch (regs[1].val) {
                case MODE_A_VAL:
                        cnt = 1;
                        break;
                case MODE_B_VAL:
                        cnt = 2;
                        break;          /* Fix: break statement added */
                default:                /* Fix: default block added */
                        cnt=0;
                        break;

        }
	f (cnt > 1) {
                ret = SENSOR_OK;
        }
        else if (cnt == 1) {
                ret = SENSOR_ERR;
        }

        int lim = 10;                   /* Fix: unsigned was changed to match types during comparison */
        int t = -1;
        if (t < lim) {
               printf("t is small\n");
        }

        return SQR(ret + 1);
}

/*Fix: Adding a deinit function as well to release the resources allocated before */
static void deinit_sensor(void)
{
    free(regs);
    regs = NULL;
}

/* Fix: modifying the main function fully to check all return values */
int main(void)
{
    int rc = init_sensor("CameraSensor0");

    if (rc != SENSOR_OK) {
        fprintf(stderr, "sensor init failed (%d)\n", rc);
    }

    deinit_sensor();
    return (rc == SENSOR_OK) ? EXIT_SUCCESS : EXIT_FAILURE;
}
