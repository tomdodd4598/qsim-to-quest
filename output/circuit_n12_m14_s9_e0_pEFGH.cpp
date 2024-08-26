#include "QuEST.h"

#include <cmath>

constexpr qreal INV_SQRT_2 = 0.707106781186547524400844362104849039;

constexpr ComplexMatrix2 SQRT_X = { .real={{INV_SQRT_2, 0.0}, {0.0, INV_SQRT_2}}, .imag={{0.0, -INV_SQRT_2}, {-INV_SQRT_2, 0.0}} };

constexpr ComplexMatrix2 SQRT_Y = { .real={{INV_SQRT_2, -INV_SQRT_2}, {INV_SQRT_2, INV_SQRT_2}}, .imag={{0.0, 0.0}, {0.0, 0.0}} };

constexpr ComplexMatrix2 SQRT_W = { .real={{INV_SQRT_2, -0.5}, {0.5, INV_SQRT_2}}, .imag={{0.0, -0.5}, {-0.5, 0.0}} };

auto sycamore_swap(qreal theta, qreal phi) {
    auto cos_t = cos(theta), sin_t = sin(theta);
    return ComplexMatrix4 { .real={{1.0, 0.0, 0.0, 0.0}, {0.0, cos_t, 0.0, 0.0}, {0.0, 0.0, cos_t, 0.0}, {0.0, 0.0, 0.0, cos(phi)}}, .imag={{0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, -sin_t, 0.0}, {0.0, -sin_t, 0.0, 0.0}, {0.0, 0.0, 0.0, -sin(phi)}} };
}

void run_circuit(Qureg const& reg) {
    unitary(reg, 0, SQRT_Y);
    unitary(reg, 1, SQRT_W);
    unitary(reg, 2, SQRT_Y);
    unitary(reg, 3, SQRT_Y);
    unitary(reg, 4, SQRT_X);
    unitary(reg, 5, SQRT_W);
    unitary(reg, 6, SQRT_X);
    unitary(reg, 7, SQRT_X);
    unitary(reg, 8, SQRT_X);
    unitary(reg, 9, SQRT_X);
    unitary(reg, 10, SQRT_Y);
    unitary(reg, 11, SQRT_Y);
    rotateZ(reg, 1, 0.8693959871027742);
    rotateZ(reg, 2, -0.5809728937821895);
    rotateZ(reg, 5, -3.1455232066056915);
    rotateZ(reg, 6, 3.5262953599473446);
    rotateZ(reg, 9, -1.0402901334038208);
    rotateZ(reg, 10, 1.2704822022121596);
    twoQubitUnitary(reg, 1, 2, sycamore_swap(1.5862983338115253, 0.5200148508319427));
    twoQubitUnitary(reg, 5, 6, sycamore_swap(1.5289739216684795, 0.5055240639761313));
    twoQubitUnitary(reg, 9, 10, sycamore_swap(1.5346175385256955, 0.5131039467233695));
    rotateZ(reg, 1, -2.1118243782923773);
    rotateZ(reg, 2, 2.4002474716129623);
    rotateZ(reg, 5, 2.510370594218442);
    rotateZ(reg, 6, -2.1295984408767894);
    rotateZ(reg, 9, 0.15501230573908462);
    rotateZ(reg, 10, 0.07517976306925431);
    unitary(reg, 0, SQRT_X);
    unitary(reg, 1, SQRT_Y);
    unitary(reg, 2, SQRT_W);
    unitary(reg, 3, SQRT_W);
    unitary(reg, 4, SQRT_W);
    unitary(reg, 5, SQRT_Y);
    unitary(reg, 6, SQRT_W);
    unitary(reg, 7, SQRT_W);
    unitary(reg, 8, SQRT_Y);
    unitary(reg, 9, SQRT_Y);
    unitary(reg, 10, SQRT_X);
    unitary(reg, 11, SQRT_W);
    rotateZ(reg, 0, 7.95878242287787);
    rotateZ(reg, 1, -7.774843741231972);
    rotateZ(reg, 2, -14.076559546984539);
    rotateZ(reg, 3, 14.218497333398785);
    rotateZ(reg, 4, 6.7102990377713985);
    rotateZ(reg, 5, -6.8557924692300185);
    rotateZ(reg, 6, -11.869086784143517);
    rotateZ(reg, 7, 11.992514358506712);
    rotateZ(reg, 8, 2.4540157696942893);
    rotateZ(reg, 9, -2.130087599403273);
    rotateZ(reg, 10, 5.854589755013336);
    rotateZ(reg, 11, -6.755719773321365);
    twoQubitUnitary(reg, 0, 1, sycamore_swap(1.2947043217999283, 0.4859467238431821));
    twoQubitUnitary(reg, 2, 3, sycamore_swap(1.541977006124425, 0.6073798124875975));
    twoQubitUnitary(reg, 4, 5, sycamore_swap(1.5138652502397498, 0.47710618607286504));
    twoQubitUnitary(reg, 6, 7, sycamore_swap(1.5849169442855044, 0.54346233613361));
    twoQubitUnitary(reg, 8, 9, sycamore_swap(1.5398075246432927, 0.5174515645943538));
    twoQubitUnitary(reg, 10, 11, sycamore_swap(1.4593314109380113, 0.5230636172671492));
    rotateZ(reg, 0, -7.370403665363804);
    rotateZ(reg, 1, 7.554342347009701);
    rotateZ(reg, 2, 15.859387461711556);
    rotateZ(reg, 3, -15.71744967529731);
    rotateZ(reg, 4, -8.338843337248123);
    rotateZ(reg, 5, 8.193349905789502);
    rotateZ(reg, 6, 12.26637631755088);
    rotateZ(reg, 7, -12.142948743187686);
    rotateZ(reg, 8, -4.874679037269875);
    rotateZ(reg, 9, 5.198607207560892);
    rotateZ(reg, 10, -5.948000038116973);
    rotateZ(reg, 11, 5.046870019808944);
    unitary(reg, 0, SQRT_Y);
    unitary(reg, 1, SQRT_W);
    unitary(reg, 2, SQRT_Y);
    unitary(reg, 3, SQRT_Y);
    unitary(reg, 4, SQRT_X);
    unitary(reg, 5, SQRT_X);
    unitary(reg, 6, SQRT_Y);
    unitary(reg, 7, SQRT_Y);
    unitary(reg, 8, SQRT_W);
    unitary(reg, 9, SQRT_X);
    unitary(reg, 10, SQRT_Y);
    unitary(reg, 11, SQRT_X);
    rotateZ(reg, 4, -10.300317334985465);
    rotateZ(reg, 8, 10.489798112305557);
    rotateZ(reg, 5, -16.935559040199575);
    rotateZ(reg, 9, 17.018814476659895);
    rotateZ(reg, 6, -17.65620553132214);
    rotateZ(reg, 10, 17.688640528946085);
    rotateZ(reg, 7, 13.72138435193195);
    rotateZ(reg, 11, -12.285441868370123);
    twoQubitUnitary(reg, 4, 8, sycamore_swap(1.589821065740506, 0.5045391214115686));
    twoQubitUnitary(reg, 5, 9, sycamore_swap(1.5472406430590444, 0.5216932173558055));
    twoQubitUnitary(reg, 6, 10, sycamore_swap(1.5124128267683938, 0.5133142626030278));
    twoQubitUnitary(reg, 7, 11, sycamore_swap(1.5707871303628709, 0.5176678491729374));
    rotateZ(reg, 4, 9.244163795666879);
    rotateZ(reg, 8, -9.054683018346786);
    rotateZ(reg, 5, 14.03202226075948);
    rotateZ(reg, 9, -13.94876682429916);
    rotateZ(reg, 6, 14.094665893757096);
    rotateZ(reg, 10, -14.062230896133155);
    rotateZ(reg, 7, -15.384431193528544);
    rotateZ(reg, 11, 16.82037367709037);
    unitary(reg, 0, SQRT_W);
    unitary(reg, 1, SQRT_X);
    unitary(reg, 2, SQRT_W);
    unitary(reg, 3, SQRT_W);
    unitary(reg, 4, SQRT_W);
    unitary(reg, 5, SQRT_Y);
    unitary(reg, 6, SQRT_W);
    unitary(reg, 7, SQRT_W);
    unitary(reg, 8, SQRT_X);
    unitary(reg, 9, SQRT_Y);
    unitary(reg, 10, SQRT_X);
    unitary(reg, 11, SQRT_Y);
    rotateZ(reg, 0, 39.909529911684075);
    rotateZ(reg, 4, -40.171428733227174);
    rotateZ(reg, 1, 38.277959915149545);
    rotateZ(reg, 5, -38.040241149679936);
    rotateZ(reg, 2, 11.883270567757798);
    rotateZ(reg, 6, -12.169262658895612);
    rotateZ(reg, 3, 14.993690269805821);
    rotateZ(reg, 7, -14.989527131529702);
    twoQubitUnitary(reg, 0, 4, sycamore_swap(1.4668587973263782, 0.4976074601121169));
    twoQubitUnitary(reg, 1, 5, sycamore_swap(1.47511091993527, 0.538612093835262));
    twoQubitUnitary(reg, 2, 6, sycamore_swap(1.603651215218248, 0.46649538437100246));
    twoQubitUnitary(reg, 3, 7, sycamore_swap(1.6160334279232749, 0.4353897326147861));
    rotateZ(reg, 0, -39.198437626672444);
    rotateZ(reg, 4, 38.936538805129345);
    rotateZ(reg, 1, -35.53420813044422);
    rotateZ(reg, 5, 35.77192689591383);
    rotateZ(reg, 2, -17.246915283138684);
    rotateZ(reg, 6, 16.96092319200087);
    rotateZ(reg, 3, -18.421895502761547);
    rotateZ(reg, 7, 18.426058641037667);
    unitary(reg, 0, SQRT_Y);
    unitary(reg, 1, SQRT_W);
    unitary(reg, 2, SQRT_X);
    unitary(reg, 3, SQRT_Y);
    unitary(reg, 4, SQRT_X);
    unitary(reg, 5, SQRT_X);
    unitary(reg, 6, SQRT_Y);
    unitary(reg, 7, SQRT_X);
    unitary(reg, 8, SQRT_Y);
    unitary(reg, 9, SQRT_X);
    unitary(reg, 10, SQRT_Y);
    unitary(reg, 11, SQRT_X);
    rotateZ(reg, 1, 16.21293450723508);
    rotateZ(reg, 2, -15.924511413914495);
    rotateZ(reg, 5, -14.76941602488768);
    rotateZ(reg, 6, 15.150188178229332);
    rotateZ(reg, 9, -11.269315813491886);
    rotateZ(reg, 10, 11.499507882300225);
    twoQubitUnitary(reg, 1, 2, sycamore_swap(1.5862983338115253, 0.5200148508319427));
    twoQubitUnitary(reg, 5, 6, sycamore_swap(1.5289739216684795, 0.5055240639761313));
    twoQubitUnitary(reg, 9, 10, sycamore_swap(1.5346175385256955, 0.5131039467233695));
    rotateZ(reg, 1, -17.455362898424685);
    rotateZ(reg, 2, 17.743785991745266);
    rotateZ(reg, 5, 14.134263412500427);
    rotateZ(reg, 6, -13.753491259158777);
    rotateZ(reg, 9, 10.384037985827149);
    rotateZ(reg, 10, -10.15384591701881);
    unitary(reg, 0, SQRT_W);
    unitary(reg, 1, SQRT_X);
    unitary(reg, 2, SQRT_Y);
    unitary(reg, 3, SQRT_X);
    unitary(reg, 4, SQRT_W);
    unitary(reg, 5, SQRT_Y);
    unitary(reg, 6, SQRT_W);
    unitary(reg, 7, SQRT_Y);
    unitary(reg, 8, SQRT_X);
    unitary(reg, 9, SQRT_W);
    unitary(reg, 10, SQRT_X);
    unitary(reg, 11, SQRT_W);
    rotateZ(reg, 0, 23.76727665574203);
    rotateZ(reg, 1, -23.583337974096132);
    rotateZ(reg, 2, -48.01832657636844);
    rotateZ(reg, 3, 48.160264362782684);
    rotateZ(reg, 4, 22.053837557903705);
    rotateZ(reg, 5, -22.199330989362323);
    rotateZ(reg, 6, -43.48607524987143);
    rotateZ(reg, 7, 43.609502824234625);
    rotateZ(reg, 8, 9.42835146066348);
    rotateZ(reg, 9, -9.104423290372464);
    rotateZ(reg, 10, 17.47848257329532);
    rotateZ(reg, 11, -18.37961259160335);
    twoQubitUnitary(reg, 0, 1, sycamore_swap(1.2947043217999283, 0.4859467238431821));
    twoQubitUnitary(reg, 2, 3, sycamore_swap(1.541977006124425, 0.6073798124875975));
    twoQubitUnitary(reg, 4, 5, sycamore_swap(1.5138652502397498, 0.47710618607286504));
    twoQubitUnitary(reg, 6, 7, sycamore_swap(1.5849169442855044, 0.54346233613361));
    twoQubitUnitary(reg, 8, 9, sycamore_swap(1.5398075246432927, 0.5174515645943538));
    twoQubitUnitary(reg, 10, 11, sycamore_swap(1.4593314109380113, 0.5230636172671492));
    rotateZ(reg, 0, -23.178897898227966);
    rotateZ(reg, 1, 23.362836579873864);
    rotateZ(reg, 2, 49.801154491095446);
    rotateZ(reg, 3, -49.6592167046812);
    rotateZ(reg, 4, -23.682381857380427);
    rotateZ(reg, 5, 23.53688842592181);
    rotateZ(reg, 6, 43.88336478327879);
    rotateZ(reg, 7, -43.7599372089156);
    rotateZ(reg, 8, -11.849014728239068);
    rotateZ(reg, 9, 12.172942898530083);
    rotateZ(reg, 10, -17.571892856398957);
    rotateZ(reg, 11, 16.670762838090926);
    unitary(reg, 0, SQRT_X);
    unitary(reg, 1, SQRT_Y);
    unitary(reg, 2, SQRT_X);
    unitary(reg, 3, SQRT_Y);
    unitary(reg, 4, SQRT_Y);
    unitary(reg, 5, SQRT_W);
    unitary(reg, 6, SQRT_Y);
    unitary(reg, 7, SQRT_W);
    unitary(reg, 8, SQRT_W);
    unitary(reg, 9, SQRT_Y);
    unitary(reg, 10, SQRT_Y);
    unitary(reg, 11, SQRT_Y);
    rotateZ(reg, 4, -25.643855855118186);
    rotateZ(reg, 8, 25.833336632438275);
    rotateZ(reg, 5, -40.648300389495404);
    rotateZ(reg, 9, 40.73155582595572);
    rotateZ(reg, 6, -39.97407974242405);
    rotateZ(reg, 10, 40.00651474004799);
    rotateZ(reg, 7, 34.64439142483994);
    rotateZ(reg, 11, -33.20844894127811);
    twoQubitUnitary(reg, 4, 8, sycamore_swap(1.589821065740506, 0.5045391214115686));
    twoQubitUnitary(reg, 5, 9, sycamore_swap(1.5472406430590444, 0.5216932173558055));
    twoQubitUnitary(reg, 6, 10, sycamore_swap(1.5124128267683938, 0.5133142626030278));
    twoQubitUnitary(reg, 7, 11, sycamore_swap(1.5707871303628709, 0.5176678491729374));
    rotateZ(reg, 4, 24.587702315799596);
    rotateZ(reg, 8, -24.398221538479504);
    rotateZ(reg, 5, 37.744763610055315);
    rotateZ(reg, 9, -37.661508173594996);
    rotateZ(reg, 6, 36.412540104859005);
    rotateZ(reg, 10, -36.38010510723507);
    rotateZ(reg, 7, -36.307438266436534);
    rotateZ(reg, 11, 37.743380749998366);
    unitary(reg, 0, SQRT_W);
    unitary(reg, 1, SQRT_X);
    unitary(reg, 2, SQRT_W);
    unitary(reg, 3, SQRT_X);
    unitary(reg, 4, SQRT_X);
    unitary(reg, 5, SQRT_Y);
    unitary(reg, 6, SQRT_X);
    unitary(reg, 7, SQRT_Y);
    unitary(reg, 8, SQRT_X);
    unitary(reg, 9, SQRT_X);
    unitary(reg, 10, SQRT_X);
    unitary(reg, 11, SQRT_W);
    rotateZ(reg, 0, 81.75554405750046);
    rotateZ(reg, 4, -82.01744287904356);
    rotateZ(reg, 1, 79.65901834823408);
    rotateZ(reg, 5, -79.42129958276446);
    rotateZ(reg, 2, 26.296897662428034);
    rotateZ(reg, 6, -26.58288975356585);
    rotateZ(reg, 3, 31.732095928132054);
    rotateZ(reg, 7, -31.727932789855927);
    twoQubitUnitary(reg, 0, 4, sycamore_swap(1.4668587973263782, 0.4976074601121169));
    twoQubitUnitary(reg, 1, 5, sycamore_swap(1.47511091993527, 0.538612093835262));
    twoQubitUnitary(reg, 2, 6, sycamore_swap(1.603651215218248, 0.46649538437100246));
    twoQubitUnitary(reg, 3, 7, sycamore_swap(1.6160334279232749, 0.4353897326147861));
    rotateZ(reg, 0, -81.04445177248883);
    rotateZ(reg, 4, 80.78255295094573);
    rotateZ(reg, 1, -76.91526656352876);
    rotateZ(reg, 5, 77.15298532899838);
    rotateZ(reg, 2, -31.660542377808927);
    rotateZ(reg, 6, 31.37455028667111);
    rotateZ(reg, 3, -35.16030116108778);
    rotateZ(reg, 7, 35.16446429936389);
    unitary(reg, 0, SQRT_X);
    unitary(reg, 1, SQRT_W);
    unitary(reg, 2, SQRT_X);
    unitary(reg, 3, SQRT_W);
    unitary(reg, 4, SQRT_W);
    unitary(reg, 5, SQRT_X);
    unitary(reg, 6, SQRT_Y);
    unitary(reg, 7, SQRT_X);
    unitary(reg, 8, SQRT_Y);
    unitary(reg, 9, SQRT_W);
    unitary(reg, 10, SQRT_W);
    unitary(reg, 11, SQRT_Y);
    rotateZ(reg, 1, 31.556473027367385);
    rotateZ(reg, 2, -31.268049934046807);
    rotateZ(reg, 5, -26.393308843169667);
    rotateZ(reg, 6, 26.774080996511316);
    rotateZ(reg, 9, -21.49834149357995);
    rotateZ(reg, 10, 21.728533562388286);
    twoQubitUnitary(reg, 1, 2, sycamore_swap(1.5862983338115253, 0.5200148508319427));
    twoQubitUnitary(reg, 5, 6, sycamore_swap(1.5289739216684795, 0.5055240639761313));
    twoQubitUnitary(reg, 9, 10, sycamore_swap(1.5346175385256955, 0.5131039467233695));
    rotateZ(reg, 1, -32.798901418556994);
    rotateZ(reg, 2, 33.08732451187758);
    rotateZ(reg, 5, 25.75815623078241);
    rotateZ(reg, 6, -25.37738407744076);
    rotateZ(reg, 9, 20.613063665915213);
    rotateZ(reg, 10, -20.382871597106877);
    unitary(reg, 0, SQRT_W);
    unitary(reg, 1, SQRT_Y);
    unitary(reg, 2, SQRT_W);
    unitary(reg, 3, SQRT_Y);
    unitary(reg, 4, SQRT_X);
    unitary(reg, 5, SQRT_W);
    unitary(reg, 6, SQRT_W);
    unitary(reg, 7, SQRT_Y);
    unitary(reg, 8, SQRT_X);
    unitary(reg, 9, SQRT_X);
    unitary(reg, 10, SQRT_X);
    unitary(reg, 11, SQRT_X);
    rotateZ(reg, 0, 39.57577088860619);
    rotateZ(reg, 1, -39.391832206960295);
    rotateZ(reg, 2, -81.96009360575232);
    rotateZ(reg, 3, 82.10203139216657);
    rotateZ(reg, 4, 37.39737607803601);
    rotateZ(reg, 5, -37.54286950949463);
    rotateZ(reg, 6, -75.10306371559935);
    rotateZ(reg, 7, 75.22649128996255);
    rotateZ(reg, 8, 16.402687151632673);
    rotateZ(reg, 9, -16.078758981341654);
    rotateZ(reg, 10, 29.102375391577308);
    rotateZ(reg, 11, -30.00350540988534);
    twoQubitUnitary(reg, 0, 1, sycamore_swap(1.2947043217999283, 0.4859467238431821));
    twoQubitUnitary(reg, 2, 3, sycamore_swap(1.541977006124425, 0.6073798124875975));
    twoQubitUnitary(reg, 4, 5, sycamore_swap(1.5138652502397498, 0.47710618607286504));
    twoQubitUnitary(reg, 6, 7, sycamore_swap(1.5849169442855044, 0.54346233613361));
    twoQubitUnitary(reg, 8, 9, sycamore_swap(1.5398075246432927, 0.5174515645943538));
    twoQubitUnitary(reg, 10, 11, sycamore_swap(1.4593314109380113, 0.5230636172671492));
    rotateZ(reg, 0, -38.98739213109213);
    rotateZ(reg, 1, 39.17133081273803);
    rotateZ(reg, 2, 83.74292152047934);
    rotateZ(reg, 3, -83.6009837340651);
    rotateZ(reg, 4, -39.025920377512726);
    rotateZ(reg, 5, 38.88042694605411);
    rotateZ(reg, 6, 75.50035324900671);
    rotateZ(reg, 7, -75.3769256746435);
    rotateZ(reg, 8, -18.823350419208257);
    rotateZ(reg, 9, 19.147278589499276);
    rotateZ(reg, 10, -29.19578567468094);
    rotateZ(reg, 11, 28.294655656372914);
    unitary(reg, 0, SQRT_X);
    unitary(reg, 1, SQRT_W);
    unitary(reg, 2, SQRT_X);
    unitary(reg, 3, SQRT_W);
    unitary(reg, 4, SQRT_W);
    unitary(reg, 5, SQRT_Y);
    unitary(reg, 6, SQRT_X);
    unitary(reg, 7, SQRT_W);
    unitary(reg, 8, SQRT_Y);
    unitary(reg, 9, SQRT_Y);
    unitary(reg, 10, SQRT_W);
    unitary(reg, 11, SQRT_W);
    rotateZ(reg, 4, -40.9873943752509);
    rotateZ(reg, 8, 41.176875152571);
    rotateZ(reg, 5, -64.36104173879124);
    rotateZ(reg, 9, 64.44429717525156);
    rotateZ(reg, 6, -62.29195395352596);
    rotateZ(reg, 10, 62.3243889511499);
    rotateZ(reg, 7, 55.56739849774794);
    rotateZ(reg, 11, -54.13145601418609);
    twoQubitUnitary(reg, 4, 8, sycamore_swap(1.589821065740506, 0.5045391214115686));
    twoQubitUnitary(reg, 5, 9, sycamore_swap(1.5472406430590444, 0.5216932173558055));
    twoQubitUnitary(reg, 6, 10, sycamore_swap(1.5124128267683938, 0.5133142626030278));
    twoQubitUnitary(reg, 7, 11, sycamore_swap(1.5707871303628709, 0.5176678491729374));
    rotateZ(reg, 4, 39.931240835932314);
    rotateZ(reg, 8, -39.741760058612215);
    rotateZ(reg, 5, 61.45750495935115);
    rotateZ(reg, 9, -61.37424952289083);
    rotateZ(reg, 6, 58.730414315960914);
    rotateZ(reg, 10, -58.69797931833698);
    rotateZ(reg, 7, -57.23044533934453);
    rotateZ(reg, 11, 58.666387822906366);
    unitary(reg, 0, SQRT_W);
    unitary(reg, 1, SQRT_X);
    unitary(reg, 2, SQRT_W);
    unitary(reg, 3, SQRT_X);
    unitary(reg, 4, SQRT_Y);
    unitary(reg, 5, SQRT_X);
    unitary(reg, 6, SQRT_W);
    unitary(reg, 7, SQRT_X);
    unitary(reg, 8, SQRT_W);
    unitary(reg, 9, SQRT_X);
    unitary(reg, 10, SQRT_X);
    unitary(reg, 11, SQRT_X);
    rotateZ(reg, 0, 123.60155820331686);
    rotateZ(reg, 4, -123.86345702485994);
    rotateZ(reg, 1, 121.04007678131862);
    rotateZ(reg, 5, -120.80235801584898);
    rotateZ(reg, 2, 40.71052475709828);
    rotateZ(reg, 6, -40.99651684823609);
    rotateZ(reg, 3, 48.47050158645827);
    rotateZ(reg, 7, -48.46633844818216);
    twoQubitUnitary(reg, 0, 4, sycamore_swap(1.4668587973263782, 0.4976074601121169));
    twoQubitUnitary(reg, 1, 5, sycamore_swap(1.47511091993527, 0.538612093835262));
    twoQubitUnitary(reg, 2, 6, sycamore_swap(1.603651215218248, 0.46649538437100246));
    twoQubitUnitary(reg, 3, 7, sycamore_swap(1.6160334279232749, 0.4353897326147861));
    rotateZ(reg, 0, -122.89046591830522);
    rotateZ(reg, 4, 122.62856709676213);
    rotateZ(reg, 1, -118.29632499661328);
    rotateZ(reg, 5, 118.5340437620829);
    rotateZ(reg, 2, -46.07416947247916);
    rotateZ(reg, 6, 45.78817738134135);
    rotateZ(reg, 3, -51.89870681941401);
    rotateZ(reg, 7, 51.902869957690115);
    unitary(reg, 0, SQRT_Y);
    unitary(reg, 1, SQRT_Y);
    unitary(reg, 2, SQRT_Y);
    unitary(reg, 3, SQRT_Y);
    unitary(reg, 4, SQRT_W);
    unitary(reg, 5, SQRT_Y);
    unitary(reg, 6, SQRT_X);
    unitary(reg, 7, SQRT_Y);
    unitary(reg, 8, SQRT_X);
    unitary(reg, 9, SQRT_W);
    unitary(reg, 10, SQRT_Y);
    unitary(reg, 11, SQRT_W);
    rotateZ(reg, 1, 46.900011547499695);
    rotateZ(reg, 2, -46.611588454179106);
    rotateZ(reg, 5, -38.017201661451644);
    rotateZ(reg, 6, 38.397973814793296);
    rotateZ(reg, 9, -31.727367173668014);
    rotateZ(reg, 10, 31.957559242476353);
    twoQubitUnitary(reg, 1, 2, sycamore_swap(1.5862983338115253, 0.5200148508319427));
    twoQubitUnitary(reg, 5, 6, sycamore_swap(1.5289739216684795, 0.5055240639761313));
    twoQubitUnitary(reg, 9, 10, sycamore_swap(1.5346175385256955, 0.5131039467233695));
    rotateZ(reg, 1, -48.1424399386893);
    rotateZ(reg, 2, 48.43086303200989);
    rotateZ(reg, 5, 37.3820490490644);
    rotateZ(reg, 6, -37.00127689572275);
    rotateZ(reg, 9, 30.842089346003284);
    rotateZ(reg, 10, -30.611897277194945);
    unitary(reg, 0, SQRT_W);
    unitary(reg, 1, SQRT_X);
    unitary(reg, 2, SQRT_X);
    unitary(reg, 3, SQRT_X);
    unitary(reg, 4, SQRT_Y);
    unitary(reg, 5, SQRT_X);
    unitary(reg, 6, SQRT_Y);
    unitary(reg, 7, SQRT_X);
    unitary(reg, 8, SQRT_W);
    unitary(reg, 9, SQRT_Y);
    unitary(reg, 10, SQRT_W);
    unitary(reg, 11, SQRT_X);
    rotateZ(reg, 0, 55.38426512147036);
    rotateZ(reg, 1, -55.20032643982446);
    rotateZ(reg, 2, -115.90186063513623);
    rotateZ(reg, 3, 116.04379842155048);
    rotateZ(reg, 4, 52.740914598168324);
    rotateZ(reg, 5, -52.88640802962693);
    rotateZ(reg, 6, -106.72005218132728);
    rotateZ(reg, 7, 106.84347975569048);
    rotateZ(reg, 8, 23.377022842601868);
    rotateZ(reg, 9, -23.05309467231085);
    rotateZ(reg, 10, 40.72626820985929);
    rotateZ(reg, 11, -41.627398228167316);
    twoQubitUnitary(reg, 0, 1, sycamore_swap(1.2947043217999283, 0.4859467238431821));
    twoQubitUnitary(reg, 2, 3, sycamore_swap(1.541977006124425, 0.6073798124875975));
    twoQubitUnitary(reg, 4, 5, sycamore_swap(1.5138652502397498, 0.47710618607286504));
    twoQubitUnitary(reg, 6, 7, sycamore_swap(1.5849169442855044, 0.54346233613361));
    twoQubitUnitary(reg, 8, 9, sycamore_swap(1.5398075246432927, 0.5174515645943538));
    twoQubitUnitary(reg, 10, 11, sycamore_swap(1.4593314109380113, 0.5230636172671492));
    rotateZ(reg, 0, -54.795886363956285);
    rotateZ(reg, 1, 54.97982504560218);
    rotateZ(reg, 2, 117.68468854986324);
    rotateZ(reg, 3, -117.54275076344899);
    rotateZ(reg, 4, -54.36945889764503);
    rotateZ(reg, 5, 54.22396546618641);
    rotateZ(reg, 6, 107.11734171473461);
    rotateZ(reg, 7, -106.9939141403714);
    rotateZ(reg, 8, -25.797686110177455);
    rotateZ(reg, 9, 26.12161428046847);
    rotateZ(reg, 10, -40.81967849296293);
    rotateZ(reg, 11, 39.918548474654905);
    unitary(reg, 0, SQRT_Y);
    unitary(reg, 1, SQRT_W);
    unitary(reg, 2, SQRT_W);
    unitary(reg, 3, SQRT_Y);
    unitary(reg, 4, SQRT_W);
    unitary(reg, 5, SQRT_Y);
    unitary(reg, 6, SQRT_X);
    unitary(reg, 7, SQRT_Y);
    unitary(reg, 8, SQRT_X);
    unitary(reg, 9, SQRT_W);
    unitary(reg, 10, SQRT_Y);
    unitary(reg, 11, SQRT_W);
}

int main(int argc, char** argv) {
    auto env = createQuESTEnv();

    auto reg_size = 12;
    auto reg = createQureg(reg_size, env);

    run_circuit(reg);

    // Analysis code here!

    destroyQureg(reg, env);
    destroyQuESTEnv(env);

    return 0;
}
