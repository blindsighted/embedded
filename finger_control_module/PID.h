class PID {
	float alpha;
	float kp_p, ki_p, kd_p;
	float kp_n, ki_n, kd_n;
	float iterm, l_error, l_time;
	float ithreshold_p, ithreshold_n;
public:
	PID(float alpha, float kp, float ki, float kd);
	PID(float alpha, float kp_p, float ki_p, float kd_p, float kp_n, float ki_n, float kd_n);
	PID(float alpha, float kp_p, float ki_p, float kd_p, float kp_n, float ki_n, float kd_n, float ithreshold_p, float ithreshold_n);
	~PID();
	float computeStep(float error, float time);
private:
	void init(float alpha, float kp_p, float ki_p, float kd_p, float kp_n, float ki_n, float kd_n, float ithreshold_p, float ithreshold_n);
};