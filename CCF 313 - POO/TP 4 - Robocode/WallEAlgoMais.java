package poo;

import robocode.*;
import robocode.Robot;
import robocode.util.Utils;

import java.awt.*;

import static robocode.util.Utils.normalRelativeAngleDegrees;

public class WallEAlgoMais extends Robot {
    int others;
    static int corner = 0;
    boolean stopWhenSeeRobot = false;
    boolean seeRobot = false;
    boolean trackisOn = false;
    boolean peek;
    double moveAmount;
    int count = 0;
    double gunTurnAmt;
    String trackName;


    /**
     * run:  Corners' main run function.
     */
    public void run() {
        // Set colors
        setBodyColor(Color.CYAN);
        setGunColor(Color.gray);
        setRadarColor(Color.BLUE);
        setBulletColor(Color.magenta);
        setScanColor(Color.BLUE);
        // get energia
        double energyTotal = getEnergy();

        // wall
        moveAmount = Math.max(getBattleFieldWidth(), getBattleFieldHeight());
        peek = false;

        // tracker
        trackName = null;



        turnLeft(getHeading() % 90);
        ahead(moveAmount);
        peek = true;
        turnGunRight(90);
        turnRight(90);

        while(true){
            peek = true;
            ahead(moveAmount);
            peek = false;
            if(getEnergy() < energyTotal*.600)
                break;
            turnRight(90);

        }
        trackisOn = true;
        setAdjustGunForRobotTurn(true);
        gunTurnAmt = 10;
        while(true) {
            this.turnGunRight(this.gunTurnAmt);
            ++this.count;
            if (this.count > 2) {
                this.gunTurnAmt = -10.0D;
            }

            if (this.count > 5) {
                this.gunTurnAmt = 10.0D;
            }

            if (this.count > 11) {
                this.trackName = null;
            }


        }
    }

    public void onScannedRobot(ScannedRobotEvent e) {
        if(!trackisOn) {
            fire(3D);
            if (peek) {
                scan();
            }
        }else{
            if (this.trackName == null || e.getName().equals(this.trackName)) {
                if (this.trackName == null) {
                    this.trackName = e.getName();
                }

                this.count = 0;
                if (e.getDistance() > 150.0D) {
                    this.gunTurnAmt = Utils.normalRelativeAngleDegrees(e.getBearing() + (this.getHeading() - this.getRadarHeading()));
                    this.turnGunRight(this.gunTurnAmt);
                    this.turnRight(e.getBearing());
                    this.ahead(e.getDistance() - 140.0D);
                } else {
                    this.gunTurnAmt = Utils.normalRelativeAngleDegrees(e.getBearing() + (this.getHeading() - this.getRadarHeading()));
                    this.turnGunRight(this.gunTurnAmt);
                    this.fire(3D);
                    if (e.getDistance() < 100.0D) {
                        if (e.getBearing() > -90.0D && e.getBearing() <= 90.0D) {
                            this.back(40.0D);
                        } else {
                            this.ahead(40.0D);
                        }
                    }

                    this.scan();
                }
            }
        }

    }
    public void onHitRobot(HitRobotEvent e) {
        if(trackisOn) {
            this.trackName = e.getName();
            this.gunTurnAmt = Utils.normalRelativeAngleDegrees(e.getBearing() + (this.getHeading() - this.getRadarHeading()));
            this.turnGunRight(this.gunTurnAmt);
            this.fire(3.0D);
            this.back(50.0D);
        }
    }


    public void onWin(WinEvent e) {
        this.turnRight(36000.0D);
    }

}

